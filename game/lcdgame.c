#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "input.h"

void lcd_game_display() {
    clearScreen(COLOR_ORANGE); // Clear the screen with orange background

    // Draw a square with the current color
    fillRectangle(30, 50, 50, 50, current_color); // Position (30,50), size 50x50
}
