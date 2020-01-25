#ifndef GAME_PAD_UTIL_
#define GAME_PAD_UTIL_

#include <genesis.h>

#define GAMEPAD_UP 0
#define GAMEPAD_RELEASED 1
#define GAMEPAD_HELD 2
#define GAMEPAD_PRESSED 3

typedef struct
{
	u16 Id;
	
	u8 A;
	u8 B;
	u8 C;
	u8 START;

	u8 Up;
	u8 Down;
	u8 Left;
	u8 Right;

	u8 X;
	u8 Y;

	u16 CurrentState;
	u16 PrevState;
}Pad;


void SetupPad(Pad* pad, u16 player);
void UpdatePad(Pad* pad);
void ResetPad(Pad* pad);

#endif