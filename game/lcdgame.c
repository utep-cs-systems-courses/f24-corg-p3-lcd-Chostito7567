#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdgame.h"

// Initialize `current_color` with a default color (e.g., white)
static u_int current_color = COLOR_WHITE; // Adjust as needed for your requirements

void lcd_game_display() {
    // Draw a square with the current color
    fillRectangle(30, 50, 50, 50, current_color); // Position (30,50), size 50x50
}
