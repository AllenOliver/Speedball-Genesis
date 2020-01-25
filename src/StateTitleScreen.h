#ifndef STATE_TITLE_SCREEN_
#define STATE_TITLE_SCREEN_

#include <genesis.h>
#include "GamePadUtil.h"
#include "SimpleState.h"



void StateTitleScreen_Start();
void StateTitleScreen_Update();
void StateTitleScreen_End();
void ChangeRasterColor();
void BlinkText();


const extern SimpleState StateTitleScreen;
#endif

