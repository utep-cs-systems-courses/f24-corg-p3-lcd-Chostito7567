#include "lcdutils.h"
#include "lcddraw.h"

void lcd_game_init() {
    lcd_init();                  // Initialize the LCD
    clearScreen(COLOR_BLACK);    // Clear the screen with a black background
}

void lcd_draw_square() {
    // Draw a square at the center of the screen
    u_char topLeftX = screenWidth / 2 - 10;  // Center horizontally
    u_char topLeftY = screenHeight / 2 - 10; // Center vertically
    u_char sideLength = 20;                  // Square side length

    fillRectangle(topLeftX, topLeftY, sideLength, sideLength, COLOR_GREEN);
}
