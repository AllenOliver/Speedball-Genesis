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

/**
 *  \brief
 *      Clears all current sprites from memory <br>
 *      Useful to call on scene changes
 */
void ClearAllSprites();


//Dealing with tilemaps

/**
 *  \brief
 *      Loads a tileset into memory
 *
 *  \param tile
 *      Tile data to load. EX. Tileset.tileset; Defined in the RES file
 *  \param tileSetIndex
 *      Tileset index to set this to.
 *  \param Method
 *      How the tiles will be loaded. 
 *      OPTIONS:
 *      CPU - Loads immediately using the CPU
 *      DMA - Loads Immediately using DMA; Locks z80
 *      DMA_Queue - Put in the DMA queue; Will be transferred at next VBlank.
 */
void LoadTileSet(const TileSet *tile, u16 tileSetIndex, TransferMethod method);

/**
 *  \brief
 *      Clears a tile from the screen
 *
 *  \param plan
 *      TThe window plan the tile is a part of.
 *  \param x
 *      X position on screen
 *  \param y
 *      Y position on screen 
 *  \param width
 *      Width of the sprite
 *  \param height
 *      Height of the sprite
 */
void ClearTile(VDPPlan plan, s16 x, s16 y, u16 width, u16 height);


/**
 *  \brief
 *      Adds A tile to memory; Draws it.
 *
 *  \param plan
 *      The window plan the tile is a part of.
 *  \param Palette
 *      The Palette colors to use
 *      OPTIONS:
 *      PAL0 - PAL3
 *  \param priority
 *      Set the tile's priority. Higher numbers render on top.
 *  \param hflip
 *      flips the sprite horizontally
 *  \param yflip
 *      flips the sprite vertically
 *  \param tileIndex
 *      Index of this tileset
 *  \param x
 *      X position on screen
 *  \param y
 *      Y position on screen 
 *  \param width
 *      Width of the sprite
 *  \param height
 *      Height of the sprite
 */
void AddTile(VDPPlan plan, u8 Palette, u8 priority, bool hflip, bool vflip, u8 tileIndex, s16 x, s16 y, u16 width, u16 height);

//Dealing with colors

/**
 *  \brief
 *      Sets the window background color
 *
 *  \param value
 *      Palette number to set it to.
 */
void SetBackgroundColor(u8 value);

/**
 *  \brief
 *      Sets a specific VDP Palette
 *
 *  \param PaletteIndex
 *      Palette index to set color data to. PAL0-PAL3
 */
void SetPalette(u16 PaletteIndex, const u16 *colorData);
