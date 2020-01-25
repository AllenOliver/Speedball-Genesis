#include <genesis.h>

typedef struct Ball
{ 
u16 StartX; // Ball's start Position X
u16 StartY; // Ball's start Position Y
int x; //Ball's current X pos
int y; //Ball's current Y pos
int SpeedX; //Ball's speed
int SpeedY;
u16 height;
u16 width;
Sprite * sprite;
}; 
