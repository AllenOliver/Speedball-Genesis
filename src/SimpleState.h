#ifndef _SIMPLE_STATE_H_
#define _SIMPLE_STATE_H_

#include <genesis.h>

typedef void _voidCallBack();

/**
 *  \brief
 *      Struct for a machine state. Think of it as a scene!
 *      
 *  \param Start
 *      Function that fires when the state is loaded in. Initialization logic goes here.
 *
 *  \param Update
 *      Happens every frame. Ideally 60fps 
 *
 *  \param End
 *      Happens after the State(scene) ends. Do your cleanup here. 
 * 
 *  \param VInterrupt
 *      Happens after a full screen redraw. Optional, and may be genesis specific. 
 *  
 * \param HInterrupt
 *      Happens after a full scanline redraw. Optional, and may be genesis specific. 
 * 
 *  Used to encapsulate and create a game scene.
 */
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


/**
 *  \brief
 *      Struct for the state machine itself. Usually defined in a GameManager and then in main.c
 *      
 *
 *  \param CurrentState
 *      The state(Scene) the game is in now. 
 *
 *  \param CurrentState
 *      The state(Scene) the game will move to next. 
 * 
 *  Used to create a game machine.
 */
typedef struct
{
	int TransisionOutFrames;
	int TransisionInFrames;

	const SimpleState* CurrentState;
	const SimpleState* ChangeTo;

} StateMachine;


/**
 *  \brief
 *      Start function for a scene/state.
 *      
 *  \param machine
 *      The game state machine.
 *
 *  \param state
 *      Current game state. 
 */
void StateMachineStart(StateMachine* machine, const SimpleState* state);

/**
 *  \brief
 *      Changes to a new scene
 *      
 *  \param machine
 *      The game state machine.
 *
 *  \param state
 *      Next scene that should be loaded. 
 */
void StateMachineChange(StateMachine* machine, const SimpleState* state);

/**
 *  \brief
 *      The current update function that should be running. 
 *      
 *  \param machine
 *      The game state machine.
 */
void StateMachineUpdate(StateMachine* machine);

/**
 *  \brief
 *      Fires at every screen refresh. Make sure to set this in the main.c <br>
 * 		- PROBABLY GENESIS SPECIFIC
 *      
 *  \param machine
 *      The game state machine. 
 */
void StateMachineVInterrupt(StateMachine* machine);

/**
 *  \brief
 *      Fires at every scanline refresh. Make sure to set this in the main.c <br>
 * 		- PROBABLY GENESIS SPECIFIC
 *      
 *  \param machine
 *      The game state machine. 
 */
void StateMachineHInterrupt(StateMachine* machine);
#endif