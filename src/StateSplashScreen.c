#include "StateSplashScreen.h"
#include "GameManager.h"
#include "Draw.h"
#include "StateLogoScreen.h"

//Shows the Sega Logo

Sprite *SegaLogo;
u16 counter = 0;
void StateSplashScreen_Start(StateMachine *machine, const SimpleState *state)
{
    ClearAllSprites();
    SegaLogo = DrawSprite(SEGA, 112, (104 - 20), PAL0, 0, FALSE, FALSE);
    SetPalette(PAL0, SEGA.palette->data);
    SPR_setAnim(SegaLogo, 0);
    DrawText("But not really tho...", 12, 18);
}

void StateSplashScreen_Update()
{
    counter++;
    if (counter >= 240)
    {
        StateMachineChange(&GameMachine, &StateLogoScreen);
    }
}

void StateSplashScreen_End()
{
    counter = 0;
    ClearText("But not really tho...", 12, 18);
}

const SimpleState StateSplashScreen =
    {
        StateSplashScreen_Start,
        StateSplashScreen_Update,
        StateSplashScreen_End};