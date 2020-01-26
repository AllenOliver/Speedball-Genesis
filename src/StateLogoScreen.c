#include "StateLogoScreen.h"
#include "GameManager.h"
#include "Draw.h"
#include "StateTitleScreen.h"
#include "../res/gfx.h"

u16 counter;
char text[] = "Allen Oliver 2020";
Sprite *logoSprite[4];
void StateLogoScreen_Start(StateMachine *machine, const SimpleState *state)
{
    counter = 0;
    VDP_setPalette(PAL2, LogoOne.palette->data);
    SPR_reset();
    logoSprite[0] = DrawSprite(LogoOne, ((320 / 2) - 64), 8, PAL2, 0, FALSE, FALSE);
    logoSprite[1] = DrawSprite(LogoTwo, (320 / 2), 8, PAL2, 0, FALSE, FALSE);
    logoSprite[2] = DrawSprite(LogoThree, ((320 / 2) - 64), 72, PAL2, 0, FALSE, FALSE);
    logoSprite[3] = DrawSprite(LogoFour, (320 / 2), 72, PAL2, 0, FALSE, FALSE);

    DrawText(text, 10, 18);
}

void StateLogoScreen_Update()
{
    counter++;
    if (counter >= 256)
    {
        StateMachineChange(&GameMachine, &StateTitleScreen);
    }
}

void StateLogoScreen_End()
{
    counter = 0;
    ClearText(text, 10, 18);
}

const SimpleState StateLogoScreen =
    {
        StateLogoScreen_Start,
        StateLogoScreen_Update,
        StateLogoScreen_End};