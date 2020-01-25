#include <genesis.h>
#include "../res/gfx.h"

//Dealing with tiles

void InitTiles();
void DrawTiles();
void RemoveTiles();

//Dealing with text

/**
 *  \brief
 *      Draws text to the screen
 *
 *  \param text
 *      Text to write
 *  \param x
 *      The X position on the screen.<br>
 *  \param y
 *      The Y position on the screen.<br>
 */
void DrawText(char *text, u16 x, u16 y);

/**
 *  \brief
 *      Clears text from the screen
 *
 *  \param sprite
 *      Text to clear
 *  \param x
 *      The X position on the screen.<br>
 *  \param y
 *      The Y position on the screen.<br>
 */
void ClearText(char *text, u16 x, u16 y);

//Dealing with sprites

/**
 *  \brief
 *      Shows a sprite on the screen
 *
 *  \param sprite
 *      Sprite to manipulate
 *  \param x
 *      The X position on the screen.<br>
 *  \param y
 *      The Y position on the screen.<br>
 */
void ShowSprite(Sprite *sprite, int x, int y);

/**
 *  \brief
 *      Hides a sprite on the screen
 *
 *  \param sprite
 *      Sprite to manipulate
 */
void HideSprite(Sprite *sprite);

/**
 *  \brief
 *      Removes a sprite from memory
 *
 *  \param sprite
 *      Sprite to Remove from memory
 */
void ReleaseSprite(Sprite *sprite);

/**
 *  \brief
 *      Sets the Horizontal flip of the sprite
 *
 *  \param sprite
 *      Sprite to manipulate
 *  \param flip
 *      Flip true or false
 */
void SetHFlip(Sprite *sprite, bool flip);

/**
 *  \brief
 *      Sets the Vertical flip of the sprite
 *
 *  \param sprite
 *      Sprite to manipulate
 *  \param flip
 *      Flip true or false
 */
void SetVFlip(Sprite *sprite, bool flip);

/**
 *  \brief
 *      Adds a sprite to memory and displays it on the screen.
 *
 *  \param spriteName
 *      Sprite's name in the res file. NOT a pointer to a sprite
 *  \param x
 *      x position on the screen
 *  \param y
 *      y position on the screen
 *  \param Palette
 *      Probably Genesis specific. The color palette to assign to the sprite. PAL0-PAL3
 *  \param Priority
 *      Sprites priority on the screen. Higher numbers rendered on top.
 *  \param flipX
 *      Sets the sprite's Horizontal Flip 
 *  \param flipY
 *      Sets the sprite's Vertical Flip
 */
Sprite *DrawSprite(const SpriteDefinition spriteName, s16 x, s16 y, u8 Palette, u8 priority, bool flipX, bool flipY);
