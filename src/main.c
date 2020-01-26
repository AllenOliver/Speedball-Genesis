#include <genesis.h>
#include "Draw.h"
#include "GameManager.h"
#include "HUD.h"
#include "Ball.h"
#include "Player.h"
#include "SimpleState.h"
#include "StateSplashScreen.h"
#include "StateGameScreen.h"

StateMachine GameMachine;
Pad Pad1;
//declarations
void init();
void VInterrupt();

void VInterrupt()
{
    StateMachineVInterrupt(&GameMachine);
}

//functions and loop
void init()
{
    // initialization
    VDP_setScreenHeight240();
    VDP_setPlanSize(64, 64);
}

int main()
{

    SYS_disableInts();
    VDP_setScreenWidth320();

    // On PAL show the extra pixels
    if (IS_PALSYSTEM)
    {
        VDP_setScreenHeight240();
    }
    else
    {
        VDP_setScreenHeight224();
    }

    VDP_setPlanSize(64, 64);

    SPR_init();

    SetupPad(&Pad1, 0);

    SYS_enableInts();
    SYS_setVIntCallback(VInterrupt);
    StateMachineStart(&GameMachine, &StateSplashScreen);

    while (TRUE)
    {
        UpdatePad(&Pad1);
        StateMachineUpdate(&GameMachine);
        SPR_update();
        VDP_waitVSync();
    }
}

