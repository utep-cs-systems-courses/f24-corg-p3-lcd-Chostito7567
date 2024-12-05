#include "lcdutils.h"
#include "lcddraw.h"

// Initialize the LCD
void lcd_game_init() {
    lcd_init();                  // Initialize the LCD
    clearScreen(COLOR_BLUE);     // Clear the screen with a blue background
}

// Draw a rectangle and write text inside
void lcd_draw_rectangle_with_text() {
    // Rectangle properties
    u_char topLeftX = screenWidth / 4;          // Left edge
    u_char topLeftY = screenHeight / 4;         // Top edge
    u_char rectWidth = screenWidth / 2;         // Rectangle width
    u_char rectHeight = screenHeight / 4;       // Rectangle height

    // Draw rectangle
    drawRectOutline(topLeftX, topLeftY, rectWidth, rectHeight, COLOR_GREEN);

    // Write text inside the rectangle
    u_char textX = topLeftX + 10;               // Position text slightly offset from the left edge
    u_char textY = topLeftY + rectHeight / 2;   // Center text vertically
    drawString5x7(textX, textY, "1,2,3,4", COLOR_WHITE, COLOR_BLUE);
}
