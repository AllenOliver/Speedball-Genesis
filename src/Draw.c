#include "Draw.h"

//Sprites

void ClearAllSprites()
{
    SPR_reset();
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

//Tilemaps

void ClearTile(VDPPlan plan, s16 x, s16 y, u16 width, u16 height)
{
    VDP_clearTileMapRect(plan, x, y, width, height);
}
void LoadTileSet(const TileSet *tile, u16 tileSetIndex, TransferMethod method)
{
    VDP_loadTileSet(tile, tileSetIndex, method);
}
void AddTile(VDPPlan plan, u8 Palette, u8 priority, bool hflip, bool vflip, u8 tileIndex, s16 x, s16 y, u16 width, u16 height)
{
    VDP_fillTileMapRect(plan, TILE_ATTR_FULL(Palette, priority, hflip, vflip, tileIndex), x, y, width, height);
}

void SetBackgroundColor(u8 value)
{
    VDP_setBackgroundColor(value);
}
void SetPalette(u16 PaletteIndex, const u16 *colorData)
{
    VDP_setPalette(PaletteIndex, colorData);
}

