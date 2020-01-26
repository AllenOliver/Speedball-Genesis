#include "Sound.h"

void InitializeSound(const u8 id, const u8* sampleName)
{
    XGM_setPCM(id, sampleName, sizeof(sampleName));
}

void PlaySound(u8 id, u8 priority, u16 channel)
{
    XGM_startPlayPCM(id, priority, channel);
}

void StartBGM(const u8 *songName)
{
    XGM_startPlay(songName);
}

void StopBGM(const u8 *songName)
{
    XGM_stopPlay(songName);
}


