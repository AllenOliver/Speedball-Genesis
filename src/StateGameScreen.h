#ifndef STATE_GAME_SCREEN_
#define STATE_GAME_SCREEN_

#include <genesis.h>
#include "GamePadUtil.h"
#include "SimpleState.h"



void StateGameScreen_Start();
void StateGameScreen_Update();
void StateGameScreen_End();
void StateGameScreen_VInterrupt();

void MovePlayer();
void moveBall();
void UpdatePlayer();
void Die();
void WaitForInput();
void SpeedUpBall();
void ResetBall();
void SetBallSpeed(int speed);
void ShowParticles(int x, int y);
void ResetPlayer();
void ResetScore();
void FlipBall();

const extern SimpleState StateGameScreen;
#endif

