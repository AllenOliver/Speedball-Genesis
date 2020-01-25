#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <genesis.h>
#include "SimpleState.h"
#include "GamePadUtil.h"

#define ANIM_SEGA 0
#define ANIM_TITLE 1

#define WALLHIT 66
#define PADDLEHIT 67
#define SPEEDUP 68

extern StateMachine GameMachine;
extern u16 GamePalette[64]; //Game palette
extern Pad Pad1;

#define LEFT_EDGE 0
#define RIGHT_EDGE 256
#define TOP_EDGE 0
#define BOTTOM_EDGE 240

extern char *Version;

#endif