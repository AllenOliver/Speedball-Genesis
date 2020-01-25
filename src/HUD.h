#include <genesis.h>
#include <string.h>
#include "../res/gfx.h"

/**
 *  \brief
 *      Draws the HUD to the screen
 */
void DrawHUD();

/**
 *  \brief
 *      Updates the HUD; Probably game specific.
 *
 *  \param score
 *      Score value to pass in
 *  \param lives
 *      amount of lives left
 *  \param speed
 *      current ball speed
 */
void updateHUD(u8 score, u8 lives, int speed);

/**
 *  \brief
 *      Adds all the HUD sprites and text to memory and renders them
 */
void initSprites();

/**
 *  \brief
 *      Clears all of the HUD text elements
 */
void clear();

/**
 *  \brief
 *      Releases all of the HUD sprites from memory.
 */
void RemoveHUDSprites();
