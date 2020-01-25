#ifndef _SIMPLE_STATE_H_
#define _SIMPLE_STATE_H_

#include <genesis.h>

typedef void _voidCallBack();

typedef struct
{
	_voidCallBack *Start;

	_voidCallBack *Update;

	_voidCallBack *End;

	_voidCallBack *VInterrupt;

	_voidCallBack *HInterrupt;

	int TransisionIn;
	int TransisionOut;
} SimpleState;



typedef struct
{
	int TransisionOutFrames;
	int TransisionInFrames;

	const SimpleState* CurrentState;
	const SimpleState* ChangeTo;

} StateMachine;



void StateMachineStart(StateMachine* machine, const SimpleState* state);
void StateMachineChange(StateMachine* machine, const SimpleState* state);
void StateMachineUpdate(StateMachine* machine);
void StateMachineVInterrupt(StateMachine* machine);
void StateMachineHInterrupt(StateMachine* machine);
#endif