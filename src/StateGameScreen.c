#include "StateGameScreen.h"
#include "StateTitleScreen.h"
#include "GameManager.h"
#include "Draw.h"
#include "Ball.h"
#include "Player.h"
#include "HUD.h"
#include "../res/sfx.h"
#include "../res/gfx.h"

//Shows the Game screen and handles input and rendering

struct Ball ball = {
    128, 112, 128, 112, -1, -1, 12, 12};

struct Player player = {
    1028, 180, 100, 0, 12, 48};

u8 LivesLeft = 1;
u8 Score = 0;
bool playing = TRUE;
u32 speedcounter = 0;
u16 particleCounter = 0;
int currentSpeed = 1;
Sprite *impact;

void StateGameScreen_Start(StateMachine *machine, const SimpleState *state)
{
    SPR_reset();
    VDP_setPalette(PAL2, imgball.palette->data); //shares the same palette
    //VDP_setPalette(PAL3, UiPanel.palette->data);
    VDP_setBackgroundColor(24);
    //VDP_fadeInPal(PAL2, 0, PAL1, PAL2, 60, TRUE);
    playing = TRUE;
    speedcounter = 0;
    LivesLeft = 3;
    particleCounter = 0;
    ResetBall();
    ResetPlayer();

    InitTiles();
    initSprites();

    waitTick(100);
    DrawTiles();
    VDP_setPalette(PAL2, imgball.palette->data);
    XGM_setPCM(PADDLEHIT, paddlehit, sizeof(paddlehit));
    XGM_setPCM(WALLHIT, wallhit, sizeof(wallhit));
    XGM_setPCM(SPEEDUP, speedup, sizeof(speedup));

    // start music

    XGM_startPlay(LevelMusic);
    impact = DrawSprite(ImpactParticles, 0, 0, 0, PAL2, FALSE, FALSE);
    player.sprite = DrawSprite(paddle, player.StartX, player.StartY, PAL2, 0, FALSE, FALSE);
    ball.sprite = DrawSprite(imgball, ball.StartX, ball.StartY, PAL2, 0, FALSE, FALSE);

    HideSprite(impact);
}

void StateGameScreen_Update()
{
    if (playing)
    {
        speedcounter++;
        moveBall();
        MovePlayer();
        UpdatePlayer();
        SpeedUpBall();
    }
    else
    {
        WaitForInput();
    }
}

void StateGameScreen_End()
{
    clear();
    //clear out all our sprites from memory
    ClearText("You Lose!", 12, 10);
    ClearText("You died.", 6, 15);
    ClearText("Press start to restart!", 2, 16);
    //RemoveHUDSprites();

    XGM_stopPlay(LevelMusic);
    //VDP_resetSprites();
}

void StateGameScreen_VInterrupt()

{
    particleCounter++;
    updateHUD(Score, LivesLeft, currentSpeed);

    if (particleCounter >= 30)
        HideSprite(impact);
}

const SimpleState StateGameScreen =
    {
        StateGameScreen_Start,
        StateGameScreen_Update,
        StateGameScreen_End,
        StateGameScreen_VInterrupt};

/*Deals with the ball's movement and collision*/
void moveBall()
{
    //Check horizontal bounds
    if (ball.x < LEFT_EDGE)
    {
        ball.x = LEFT_EDGE + ball.width - 1;
        ball.SpeedX = -ball.SpeedX;
        XGM_startPlayPCM(WALLHIT, 1, SOUND_PCM_CH2);
        ShowParticles(ball.x - 8, ball.y);
        FlipBall();
    }
    else if (ball.x + ball.width > RIGHT_EDGE)
    {
        ball.x = RIGHT_EDGE - ball.width - 1;
        ball.SpeedX = -ball.SpeedX;
        XGM_startPlayPCM(WALLHIT, 1, SOUND_PCM_CH2);
        ShowParticles(ball.x + 8, ball.y);
        FlipBall();
    }
    //Check vertical bounds
    if (ball.y < TOP_EDGE)
    {
        ball.y = TOP_EDGE + ball.height - 1;
        ball.SpeedY = -ball.SpeedY;
        XGM_startPlayPCM(WALLHIT, 1, SOUND_PCM_CH2);
        ShowParticles(ball.x, ball.y - 8);
        FlipBall();
    }
    else if (ball.y - ball.height > BOTTOM_EDGE - 1)
    {
        ball.y = BOTTOM_EDGE + ball.height - 8;
        ball.SpeedY = -ball.SpeedY;
        Die();
    }

    //Check for collision with paddle
    if (ball.x < player.x + player.width - 1 && ball.x + ball.width > player.x + 1)
    {
        if (ball.y < player.StartY + player.height - 1 && ball.y + ball.height >= player.StartY + 1)
        {
            //XGM_startPlayPCM(PADDLEHIT, 1, SOUND_PCM_CH2);
            XGM_startPlayPCM(PADDLEHIT, 1, SOUND_PCM_CH3);
            ball.y = player.StartY - ball.height - 1;
            ball.SpeedY = -ball.SpeedY;
            Score++;
            ShowParticles(ball.x, ball.y + 8);
            FlipBall();
        }
    }

    //Position the ball
    ball.x += ball.SpeedX;
    ball.y += ball.SpeedY;

    SPR_setPosition(ball.sprite, ball.x, ball.y);
}

/*Sets Paddle's speed and handles input.*/
void MovePlayer()
{
    if (Pad1.Right == GAMEPAD_HELD)
        player.SpeedX = 3;
    else if (Pad1.Left == GAMEPAD_HELD)
        player.SpeedX = -3;
    else
    {
        if ((Pad1.Right == GAMEPAD_RELEASED) | (Pad1.Left == GAMEPAD_RELEASED))
        {
            player.SpeedX = 0;
        }
    }
}

/*Checks Player's collision and sets the sprite location*/
void UpdatePlayer()
{
    /*Add the player's velocity to its position*/
    player.x += player.SpeedX;

    /*Keep the player within the bounds of the screen*/
    if (player.x < LEFT_EDGE + 1)
        player.x = LEFT_EDGE;
    if (player.x + player.width > RIGHT_EDGE - 1)
        player.x = RIGHT_EDGE - player.width;

    /*Let the Sprite engine position the sprite*/
    SPR_setPosition(player.sprite, player.x, player.StartY);
}

/*Handles death logic*/
void Die()
{
    LivesLeft--;
    clear();
    //updateHUD(Score, LivesLeft);
    DrawText("You died.", 6, 15);
    DrawText("Press start to restart!", 2, 16);
    player.SpeedX = 0;
    ClearText("Okay, Take a break.", 13, 3);
    ResetBall();
    ResetScore();
    playing = FALSE;
    if (LivesLeft == 0)
    {
        DrawText("You Lose!", 12, 10);
        RemoveTiles();
    }
}

void FlipBall()
{
    if (ball.SpeedX == -1 && ball.SpeedY == -1)
    {
        SetHFlip(ball.sprite, FALSE);
        SetVFlip(ball.sprite, FALSE);
    }
    else if (ball.SpeedX == 1 && ball.SpeedY == -1)
    {
        SetHFlip(ball.sprite, TRUE);
        SetVFlip(ball.sprite, FALSE);
    }
    else if (ball.SpeedX == -1 && ball.SpeedY == 1)
    {
        SetHFlip(ball.sprite, FALSE);
        SetVFlip(ball.sprite, TRUE);
    }
    else
    {
        SetHFlip(ball.sprite, TRUE);
        SetVFlip(ball.sprite, TRUE);
    }
}

/*Sets the loop to a state of limbo waiting on player input.*/
void WaitForInput()
{
    ball.x = ball.StartX;
    ball.y = ball.StartY;
    player.SpeedX = 0;
    if ((Pad1.START == GAMEPAD_PRESSED) && (LivesLeft == 0))
    {
        StateMachineChange(&GameMachine, &StateTitleScreen);
    }
    else if ((Pad1.START == GAMEPAD_PRESSED) & (LivesLeft > 0))
    {
        playing = TRUE;
        ClearText("You died.", 6, 15);
        ClearText("Press start to restart!", 2, 16);
    }
}

/*Speeds up the ball at a certain interval.*/
void SpeedUpBall()
{
    switch (Score)
    {
    case 10:
        SetBallSpeed(2);
        break;
    case 25:
        SetBallSpeed(3);
        break;
    case 35:
        SetBallSpeed(1);
        break;
    case 45:
        SetBallSpeed(3);
        break;
    case 55:
        SetBallSpeed(4);
        break;
    case 70:
        SetBallSpeed(5);
        break;
    }
}

/*Resets the ball's speed and the Speed up counter.*/
void ResetBall()
{
    ball.SpeedX = -1;
    ball.SpeedY = -1;
    speedcounter = 0;
    FlipBall();
}

/*Resets the player's speed.*/
void ResetPlayer()
{
    player.SpeedX = 0;
}

/*Resets the game score.*/
void ResetScore()
{
    Score = 0;
}

/*Sets the X and Y speed of the ball.*/
void SetBallSpeed(int speed)
{
    if (ball.SpeedX > 0)
    {
        ball.SpeedX = speed;
    }
    else
    {
        ball.SpeedX = -speed;
    }
    if (ball.SpeedY > 0)
    {
        ball.SpeedY = speed;
    }
    else
    {
        ball.SpeedY = -speed;
    }

    currentSpeed = speed;
    updateHUD(Score, LivesLeft, currentSpeed);
}

void ShowParticles(int x, int y)
{
    particleCounter = 0; //reset counter
    ShowSprite(impact, x, y);
}
