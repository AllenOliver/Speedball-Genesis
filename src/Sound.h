#include <genesis.h>
#include "../res/sfx.h"

/**
 *  \brief
 *      Adds a sound sample to memory <br>
 *      ID NEEDS TO BE 64>; ANYTHING SMALLER WILL BE IGNORED
 *
 *  \param id
 *      The ID of the sample; Greater than 64.
 *  \param sampleName
 *      Name of the sample in the res file.<br>
 */
void InitializeSound(const u8 id, const u8* sampleName);

/**
 *  \brief
 *      Plays an initalized sound. <br>
 *      If channel is currently playing, highest priority plays. 
 *  \param id
 *      ID of the sample.
 *  \param x
 *      The higher priority sample will  play first on overlap. MAX 15
 *  \param Channel
 *      Sound Channel to play the sample on. SOUND_PCM_CH1 - SOUND_PCM_CH4 
 */
void PlaySound(u8 id, u8 priority, u16 channel);

/**
 *  \brief
 *      Starts a looping Background Song
 *
 *  \param songName
 *      The song to be started.
 */
void StartBGM(const u8 *songName);

/**
 *  \brief
 *      Stops a looping Background Song
 *
 *  \param songName
 *      The song to be stopped.
 */
void StopBGM(const u8 *songName);