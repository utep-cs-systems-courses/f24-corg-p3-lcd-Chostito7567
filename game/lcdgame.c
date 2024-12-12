#include "lcdgame.h"
#include "lcddraw.h"
#include "input.h"

#define COLOR_ORANGE 0xFD20 // Define orange color

// Global variables
unsigned int random_sequence[4]; // Stores the sequence
unsigned int game_state = GAME_INIT; // Current game state

void lcd_game_init() {
    lcd_init(); // Initialize LCD
    clearScreen(COLOR_ORANGE);

    // Generate random sequence (from 1 to 4)
    for (int i = 0; i < 4; i++) {
        random_sequence[i] = (rand() % 4) + 1; // Generate numbers between 1 and 4
    }

    game_state = GAME_DISPLAY; // Start with displaying the sequence
}

void lcd_game_display() {
    clearScreen(COLOR_ORANGE); // Clear the screen with orange

    // Display the random sequence on the screen
    for (int i = 0; i < 4; i++) {
        char str[2];
        sprintf(str, "%d", random_sequence[i]);
        drawChar5x7(10 + (i * 20), 80, str[0], COLOR_WHITE, COLOR_ORANGE); // Display numbers in white
    }
}

void lcd_game_update() {
    if (game_state == GAME_DISPLAY) {
        lcd_game_display(); // Display the random sequence
        game_state = GAME_WAIT_INPUT; // Move to the input state
    } else if (game_state == GAME_WAIT_INPUT) {
        int result = input_process(random_sequence, 4); // Process input
        if (result == 1) {
            clearScreen(COLOR_GREEN); // Show green for correct input
        } else if (result == -1) {
            clearScreen(COLOR_RED); // Show red for incorrect input
        }
        game_state = GAME_DISPLAY; // Restart the game
    }
}
