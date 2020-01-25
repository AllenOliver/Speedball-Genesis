#include "StateTitleScreen.h"
#include "GameManager.h"
#include "Draw.h"
#include "StateGameScreen.h"
#include "../res/gfx.h"
#include "../res/sfx.h"

//Shows the the title screen and handles input

char PressStart[] = "Press Start!";
char Credits[] = "Credits";

Sprite *titleLogo;
Sprite *Background[4];
u16 time;
u16 colorIndex;
float TitleScrollSpeed = .3f;
void StateTitleScreen_Start(StateMachine *machine, const SimpleState *state)
{
    SPR_reset();
    VDP_setPalette(PAL1, DepthBGOne.palette->data);
    VDP_setBackgroundColor(24);
    XGM_startPlay(TitleMusic);

    VDP_loadTileSet(TitleScreenTile.tileset, 2, DMA);
    VDP_setPalette(PAL2, tile.palette->data); //load into PAL2

    //Load them into screen
    for (u16 i = 0; i < 22; i++) //Half the screen; plus one for overflow
    {
        for (u16 j = 0; j < 64; j++)
        {
            VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, 2), j, i, 1, 1);
        }
    }

    titleLogo = DrawSprite(GameLogo, (320 / 2) - 48, ((240 / 2) - 32) - 40, PAL1, 1, FALSE, FALSE);

    //create Left half
    Background[0] = DrawSprite(DepthBGOne, 0, 160, PAL1, 0, FALSE, FALSE);
    Background[1] = DrawSprite(DepthBGTwo, 80, 160, PAL1, 0, FALSE, FALSE);
    Background[2] = DrawSprite(DepthBGOne, 240, 160, PAL1, 0, FALSE, TRUE);
    Background[3] = DrawSprite(DepthBGTwo, 160, 160, PAL1, 0, FALSE, TRUE);

    DrawText(PressStart, 12, 22);
    DrawText("Allen Oliver 2020", 10, 26);
    DrawText("V 0.5", 3, 26);
}

void StateTitleScreen_Update()
{
    time++;
    if (time >= 30) //2 fps
    {
        BlinkText();
    }
    if ((Pad1.A == GAMEPAD_PRESSED) | (Pad1.START == GAMEPAD_PRESSED))
        StateMachineChange(&GameMachine, &StateGameScreen);
}

bool TextShowing = FALSE;
void BlinkText()
{
    if (TextShowing == TRUE)
    {

        DrawText(PressStart, 12, 22);
        time = 0;
        TextShowing = FALSE;
    }
    else
    {
        ClearText(PressStart, 12, 22);
        time = 0;
        TextShowing = TRUE;
    }
}

void StateTitleScreen_End()
{
    ClearText("Speed Ball", 12, 8);
    ClearText(PressStart, 12, 22);
    ClearText("Allen Oliver 2020", 10, 26);
    ClearText("V 0.5", 3, 26);
    ReleaseSprite(titleLogo);
    ReleaseSprite(Background[0]);
    ReleaseSprite(Background[1]);
    ReleaseSprite(Background[2]);
    ReleaseSprite(Background[3]);

    for (u16 i = 0; i < 22; i++) //Half the screen; plus one for overflow
    {
        for (u16 j = 0; j < 64; j++)
        {
            VDP_clearTileMapRect(PLAN_B, j, i, 1, 1);
        }
    }
    XGM_stopPlay(TitleMusic);
}

const SimpleState StateTitleScreen =
    {
        StateTitleScreen_Start,
        StateTitleScreen_Update,
        StateTitleScreen_End};

void ChangeRasterColor() //unused, but a really neat effect
{

    switch (colorIndex)
    {
    case 0: //
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 1:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 2:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 3:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 4:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 5:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 6:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 7:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 8:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 9:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 10:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 11:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 12:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x1de948));
        VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 13:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        //VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    case 14:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0xff00bc));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0x000000));
        //VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR());
        break;
    case 15:
        VDP_setPaletteColor(33, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(34, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(35, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(36, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(37, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(38, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(39, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(40, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(41, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(42, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(43, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(44, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(45, RGB24_TO_VDPCOLOR(0x000000));
        VDP_setPaletteColor(46, RGB24_TO_VDPCOLOR(0xff00bc));
        //VDP_setPaletteColor(47, RGB24_TO_VDPCOLOR(0x000000));
        break;
    }

    colorIndex++;
    if (colorIndex >= 14)
    {
        colorIndex = 0; //set back to zero after colors are cycled
    }
    time = 0; //reset Timer
}
