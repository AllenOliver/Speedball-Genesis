/*Handles drawing and updating UI*/
#include "HUD.h"
#include "Draw.h"

char scoreText[3] = "0";
char livesText[3] = "0";
Sprite *Lives[3];
Sprite *SpeedNumberPanels[5];
Sprite *SpeedNumbers[6];
Sprite *uiPanels[4];

/**/
void initSprites()
{
    //Draw Lives
    Lives[0] = DrawSprite(LifeCounter, 270, 40, PAL2, 1, FALSE, FALSE);
    Lives[1] = DrawSprite(LifeCounter, 280, 40, PAL2, 1, FALSE, FALSE);
    Lives[2] = DrawSprite(LifeCounter, 290, 40, PAL2, 1, FALSE, FALSE);

    //Draw Speed number holders
    SpeedNumberPanels[0] = DrawSprite(SpeedNumberPanel, 270, 100, PAL2, 0, FALSE, FALSE);
    SpeedNumberPanels[1] = DrawSprite(SpeedNumberPanel, 270, 124, PAL2, 0, FALSE, FALSE);
    SpeedNumberPanels[2] = DrawSprite(SpeedNumberPanel, 270, 148, PAL2, 0, FALSE, FALSE);
    SpeedNumberPanels[3] = DrawSprite(SpeedNumberPanel, 270, 172, PAL2, 0, FALSE, FALSE);
    SpeedNumberPanels[4] = DrawSprite(SpeedNumberPanel, 270, 196, PAL2, 0, FALSE, FALSE);

    //Draw Numbers
    SpeedNumbers[0] = DrawSprite(SpeedNumberOne, 282, 104, PAL2, 1, FALSE, FALSE);
    SpeedNumbers[1] = DrawSprite(SpeedNumberTwo, 282, 128, PAL2, 1, FALSE, FALSE);
    SpeedNumbers[2] = DrawSprite(SpeedNumberThree, 282, 152, PAL2, 1, FALSE, FALSE);
    SpeedNumbers[3] = DrawSprite(SpeedNumberFour, 282, 176, PAL2, 1, FALSE, FALSE);
    SpeedNumbers[4] = DrawSprite(SpeedNumberFive, 282, 200, PAL2, 1, FALSE, FALSE);

    //Text Above the panels
    SpeedNumbers[5] = DrawSprite(SpeedText, 256, 76, PAL2, 0, FALSE, FALSE);

    //Draw UI panel itself
    uiPanels[0] = DrawSprite(UiPanel, 256, 0, PAL2, 0, FALSE, FALSE);
    uiPanels[1] = DrawSprite(UiPanel, 288, 0, PAL2, 0, FALSE, TRUE);
    uiPanels[2] = DrawSprite(UiPanel, 256, 112, PAL2, 0, TRUE, FALSE);
    uiPanels[3] = DrawSprite(UiPanel, 288, 112, PAL2, 0, TRUE, TRUE);

    //Hide all the speed numbers
    for (u8 i = 1; i < 4; i++)
    {
        HideSprite(SpeedNumbers[i]);
    }
}

void DrawHUD()
{
    DrawText("Score", 33, 1);
    DrawText(scoreText, 35, 2);
    DrawText("Lives", 33, 4);
}

void updateHUD(u8 score, u8 lives, int speed)
{
    sprintf(scoreText, "%d", score);
    //sprintf(livesText, "%d", lives);
    switch (lives)
    {
    case 2:
        HideSprite(Lives[0]);
        break;
    case 1:
        HideSprite(Lives[1]);
        break;
    case 0:
        HideSprite(Lives[2]);
        break;
    default:
        break;
    }

    switch (speed)
    {
    case 1:
        ShowSprite(SpeedNumbers[0], 282, 104);
        HideSprite(SpeedNumbers[1]);
        HideSprite(SpeedNumbers[2]);
        HideSprite(SpeedNumbers[3]);
        HideSprite(SpeedNumbers[4]);
        break;
    case 2:
        ShowSprite(SpeedNumbers[0], 282, 104);
        ShowSprite(SpeedNumbers[1], 282, 128);
        HideSprite(SpeedNumbers[2]);
        HideSprite(SpeedNumbers[3]);
        HideSprite(SpeedNumbers[4]);
        break;
    case 3:
        ShowSprite(SpeedNumbers[0], 282, 104);
        ShowSprite(SpeedNumbers[1], 282, 128);
        ShowSprite(SpeedNumbers[2], 282, 152);
        HideSprite(SpeedNumbers[3]);
        HideSprite(SpeedNumbers[4]);
        break;
    case 4:
        ShowSprite(SpeedNumbers[0], 282, 104);
        ShowSprite(SpeedNumbers[1], 282, 128);
        ShowSprite(SpeedNumbers[2], 282, 152);
        ShowSprite(SpeedNumbers[3], 282, 176);
        HideSprite(SpeedNumbers[4]);
        break;
    case 5:
        ShowSprite(SpeedNumbers[0], 282, 104);
        ShowSprite(SpeedNumbers[1], 282, 128);
        ShowSprite(SpeedNumbers[2], 282, 152);
        ShowSprite(SpeedNumbers[3], 282, 176);
        ShowSprite(SpeedNumbers[4], 282, 200);
        break;
    }
    DrawHUD(); //Redraw to screen
}

void clear()
{
    ClearText("Score", 33, 1);
    ClearText("12345", 34, 2); //This one just clears 5 text spaces. Hacky
    ClearText("Lives", 33, 4);
}

void RemoveHUDSprites()
{
    //Life Counters
    ReleaseSprite(Lives[0]);
    ReleaseSprite(Lives[1]);
    ReleaseSprite(Lives[2]);

    //Speed number sprites; Including text above
    ReleaseSprite(SpeedNumbers[0]);
    ReleaseSprite(SpeedNumbers[1]);
    ReleaseSprite(SpeedNumbers[2]);
    ReleaseSprite(SpeedNumbers[3]);
    ReleaseSprite(SpeedNumbers[4]);
    ReleaseSprite(SpeedNumbers[5]);

    //UI holders for speed numbers; Remove em
    ReleaseSprite(SpeedNumberPanels[0]);
    ReleaseSprite(SpeedNumberPanels[1]);
    ReleaseSprite(SpeedNumberPanels[2]);
    ReleaseSprite(SpeedNumberPanels[3]);
    ReleaseSprite(SpeedNumberPanels[4]);

    //UI Panels
    ReleaseSprite(uiPanels[0]);
    ReleaseSprite(uiPanels[1]);
    ReleaseSprite(uiPanels[2]);
    ReleaseSprite(uiPanels[3]);
}
