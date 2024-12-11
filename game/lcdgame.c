#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <stdlib.h>  // For rand()
#include <msp430.h>  // For MSP430 registers and definitions

#define COLOR_ORANGE 0xFC00  // Correct orange color

static unsigned int number_array[4];  // Array to hold random numbers

void lcd_game_init() {
    lcd_init();                  // Initialize the LCD
    clearScreen(COLOR_BLUE);     // Clear the screen with blue

    // Use the Timer_A counter for random seed
    srand((unsigned int) TA0CCR0);  // Use Timer_A capture/compare register as seed
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
