#include <genesis.h>

typedef struct Player
{ 
u16 StartX; // Ball's start Position X
u16 StartY; // Ball's start Position Y
int x; //Players's current X pos
int SpeedX; //Player's speed
u16 height;
u16 width;
Sprite * sprite;
}; 