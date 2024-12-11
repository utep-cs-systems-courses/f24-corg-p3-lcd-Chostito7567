#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <stdlib.h>  // For rand()
#include <time.h>    // For seeding rand()

#define COLOR_ORANGE 0xFC00  // Corrected orange color definition

static unsigned int number_array[4];  // Array to hold random numbers

void lcd_game_init() {
    lcd_init();                  // Initialize the LCD
    clearScreen(COLOR_BLUE);     // Clear the screen with blue
    srand(time(NULL));           // Seed rand() with current time for true randomness
}

void lcd_draw_square() {
    fillRectangle(30, 50, 60, 60, COLOR_ORANGE);  // Draw orange square
}

void lcd_game_display() {
    // Populate the number array with random values between 1 and 4
    for (int i = 0; i < 4; i++) {
        number_array[i] = (rand() % 4) + 1;
    }

    // Display the numbers inside the square
    char buffer[2];
    for (int i = 0; i < 4; i++) {
        sprintf(buffer, "%d", number_array[i]);
        drawString5x7(40 + i * 10, 70, buffer, COLOR_WHITE, COLOR_ORANGE);
    }
}
