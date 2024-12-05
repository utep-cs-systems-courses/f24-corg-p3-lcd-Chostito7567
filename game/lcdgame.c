#include <msp430.h>
#include <stdio.h>
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"

extern int switches;  // Use switches updated by interrupt handler

// Game variables
static int lives = 3;
static int round = 1;
static int sequence[10];        // Store the sequence (max length 10)
static int sequence_length = 0; // Current length of the sequence
static int user_input_index = 0;

// Jingle mappings for buttons
void play_jingle(int button) {
    switch (button) {
        case 1: play_jingle1(); break;
        case 2: play_jingle2(); break;
        case 3: play_jingle3(); break;
        case 4: play_jingle4(); break;
    }
}

// Draw lives and round counter
void draw_game_info() {
    char buffer[16];
    // Draw lives
    sprintf(buffer, "Lives: %d", lives);
    drawString5x7(5, 5, buffer, COLOR_WHITE, COLOR_BLUE);

    // Draw round counter
    sprintf(buffer, "Round: %d", round);
    drawString5x7(screenWidth - 50, 5, buffer, COLOR_WHITE, COLOR_BLUE);
}

// Display the prompt sequence
void display_sequence() {
    clearScreen(COLOR_BLUE);        // Clear screen
    draw_game_info();               // Draw game info
    drawRectOutline(30, 50, 60, 40, COLOR_GREEN); // Rectangle for sequence

    for (int i = 0; i < sequence_length; i++) {
        char buffer[2];
        sprintf(buffer, "%d", sequence[i]);
        drawString5x7(40 + i * 10, 70, buffer, COLOR_WHITE, COLOR_BLUE);
        play_jingle(sequence[i]);   // Play jingle for each number
        __delay_cycles(1000000);   // Delay between prompts
    }

    clearScreen(COLOR_BLUE);        // Clear after showing sequence
    draw_game_info();
    drawRectOutline(30, 50, 60, 40, COLOR_GREEN); // Redraw rectangle
}

// Initialize the game
void lcd_game_init() {
    lcd_init();
    clearScreen(COLOR_BLUE);
    sequence_length = 1;
    sequence[0] = rand() % 4 + 1;  // Start with one random number
}

// Main game logic
void lcd_game_play() {
    while (lives > 0) {
        display_sequence();   // Show the prompt sequence

        // Wait for user input
        user_input_index = 0;
        while (user_input_index < sequence_length) {
            if (switches & SW1) {
                play_jingle(1);
                if (sequence[user_input_index++] != 1) lives--;
            } else if (switches & SW2) {
                play_jingle(2);
                if (sequence[user_input_index++] != 2) lives--;
            } else if (switches & SW3) {
                play_jingle(3);
                if (sequence[user_input_index++] != 3) lives--;
            } else if (switches & SW4) {
                play_jingle(4);
                if (sequence[user_input_index++] != 4) lives--;
            }
            __delay_cycles(300000); // Debounce delay
        }

        // Check if the player still has lives
        if (lives > 0) {
            sequence[sequence_length++] = rand() % 4 + 1; // Add a new number
            round++;                                      // Increment round
        }
    }

    // Game over
    clearScreen(COLOR_RED);
    drawString5x7(30, 70, "GAME OVER", COLOR_WHITE, COLOR_RED);
}
