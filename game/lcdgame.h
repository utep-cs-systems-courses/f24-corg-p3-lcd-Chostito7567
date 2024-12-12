#ifndef LCDGAME_H
#define LCDGAME_H

#include "lcdutils.h"

#define GAME_INIT 0
#define GAME_DISPLAY 1
#define GAME_WAIT_INPUT 2

void lcd_game_init();    // Initialize the game
void lcd_game_display(); // Display the random sequence
void lcd_game_update();  // Update game state and logic

#endif // LCDGAME_H
