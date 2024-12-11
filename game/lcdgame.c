#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <stdlib.h>

void lcd_game_display() {
    clearScreen(COLOR_BLUE);
    lcd_draw_square();
    lcd_display_numbers();
}

void lcd_draw_square() {
    u_char col = screenWidth / 4;
    u_char row = screenHeight / 4;
    u_char width = screenWidth / 2;
    u_char height = screenHeight / 2;

    fillRectangle(col, row, width, height, COLOR_GREEN);  // Draw a green square
}

void lcd_display_numbers() {
    char numbers[5];
    for (int i = 0; i < 4; i++) {
        numbers[i] = (rand() % 4) + 1;  // Generate random numbers from 1-4
    }
    numbers[4] = '\0';  // Null-terminate the array for display

    // Display numbers inside the square
    drawString5x7(screenWidth / 2 - 20, screenHeight / 2, numbers, COLOR_WHITE, COLOR_GREEN);
}
