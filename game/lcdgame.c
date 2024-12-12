#include "lcdgame.h"
#include "lcddraw.h"
#include "lcdutils.h"

void lcd_game_init() {
    lcd_init();
    clearScreen(COLOR_ORANGE);
}

void lcd_game_display_correct() {
    clearScreen(COLOR_GREEN);  // Display green for "Correct"
}

void lcd_game_display_incorrect() {
    clearScreen(COLOR_RED);    // Display red for "Incorrect"
}
