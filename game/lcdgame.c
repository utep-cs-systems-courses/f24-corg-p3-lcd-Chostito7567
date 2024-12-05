#include "lcdutils.h"
#include "lcddraw.h"

// Initialize the LCD
void lcd_game_init() {
    lcd_init();                  // Initialize the LCD
    clearScreen(COLOR_BLUE);     // Clear the screen with a blue background
}

// Draw a green square in the center of the screen
void lcd_draw_square() {
    u_char topLeftX = screenWidth / 2 - 10;  // Center horizontally
    u_char topLeftY = screenHeight / 2 - 10; // Center vertically
    u_char sideLength = 20;                  // Square side length

    fillRectangle(topLeftX, topLeftY, sideLength, sideLength, COLOR_GREEN);
}
