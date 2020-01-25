#include "Draw.h"

/*Initializes the game screen tiles*/
void InitTiles()
{
    VDP_loadTileSet(tile.tileset, 1, DMA);
    VDP_setPalette(PAL1, tile.palette->data); //load into PAL0
}

void ShowSprite(Sprite *sprite, int x, int y)
{
    SPR_setVisibility(sprite, VISIBLE);
    SPR_setPosition(sprite, x, y);
}

void HideSprite(Sprite *sprite)
{
    SPR_setVisibility(sprite, HIDDEN);
}

void ReleaseSprite(Sprite *sprite)
{
    SPR_releaseSprite(sprite);
}

/*Fills the screen with tiles 1-by-1*/
void DrawTiles()
{
    for (u16 i = 0; i < 28; i++)
    {
        for (u16 j = 0; j < 32; j++)
        {
            VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, 1), j, i, 1, 1);
            waitSubTick(50);
        }
    }
}

/*Removes tiles from the screen 1-by-1*/
void RemoveTiles()
{
    for (u16 i = 0; i < 28; i++)
    {
        for (u16 j = 0; j < 40; j++)
        {
            VDP_clearTileMapRect(PLAN_B, j, i, 1, 1);
            waitSubTick(50);
        }
    }
}

void DrawText(char *text, u16 x, u16 y)
{
    VDP_drawText(text, x, y);
}

void ClearText(char *text, u16 x, u16 y)
{
    VDP_clearText(x, y, strlen(text));
}

Sprite *DrawSprite(const SpriteDefinition spriteName, s16 x, s16 y, u8 Palette, u8 priority, bool flipX, bool flipY)
{
    return SPR_addSprite(&spriteName, x, y, TILE_ATTR(Palette, priority, flipX, flipY));
}

void SetHFlip(Sprite *sprite, bool flip)
{
    SPR_setHFlip(sprite, flip);
}

void SetVFlip(Sprite *sprite, bool flip)
{
    SPR_setVFlip(sprite, flip);
}