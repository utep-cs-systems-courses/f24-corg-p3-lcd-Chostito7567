#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"
#include <stdlib.h>  // For rand()

// Game variables
static int sequence[10];        // Store the sequence (max length 10)
static int sequence_length = 0; // Current length of the sequence
static int user_input_index = 0;
static int lives = 3;           // Number of lives
static int round = 1;           // Current round
static int redraw_screen = 1;   // Flag to indicate when to redraw

// Jingle mappings for buttons
void play_jingle(int button) {
    switch (button) {
        case 1: play_jingle1(); break;
        case 2: play_jingle2(); break;
        case 3: play_jingle3(); break;
        case 4: play_jingle4(); break;
    }
}

// Draw static game info
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
    draw_game_info();               // Draw game info
    drawRectOutline(30, 50, 60, 40, COLOR_GREEN); // Rectangle for sequence

    for (int i = 0; i < sequence_length; i++) {
        char buffer[2];
        sprintf(buffer, "%d", sequence[i]);
        drawString5x7(40 + i * 10, 70, buffer, COLOR_WHITE, COLOR_BLUE);
        play_jingle(sequence[i]);   // Play jingle for each number
        __delay_cycles(1000000);    // Delay between prompts
    }
}

// Initialize the game
void lcd_game_init() {
    lcd_init();
    clearScreen(COLOR_BLUE);
    srand(1234); // Seed the random number generator
    sequence_length = 1;
    sequence[0] = rand() % 4 + 1;  // Start with one random number
    redraw_screen = 1;
}

// Main game logic
void lcd_game_play() {
    while (lives > 0) {
        if (redraw_screen) {
            clearScreen(COLOR_BLUE);
            display_sequence(); // Show the prompt sequence
            redraw_screen = 0;
        }

        // Wait for user input
        user_input_index = 0;
        while (user_input_index < sequence_length) {
            if (switches & SW1) {
                play_jingle(1);
                if (sequence[user_input_index++] != 1) {
                    lives--; // Lose a life on incorrect input
                    redraw_screen = 1;
                    break;
                }
            } else if (switches & SW2) {
                play_jingle(2);
                if (sequence[user_input_index++] != 2) {
                    lives--;
                    redraw_screen = 1;
                    break;
                }
            } else if (switches & SW3) {
                play_jingle(3);
                if (sequence[user_input_index++] != 3) {
                    lives--;
                    redraw_screen = 1;
                    break;
                }
            } else if (switches & SW4) {
                play_jingle(4);
                if (sequence[user_input_index++] != 4) {
                    lives--;
                    redraw_screen = 1;
                    break;
                }
            }
            __delay_cycles(300000); // Debounce delay
        }

        if (lives > 0 && user_input_index == sequence_length) {
            sequence[sequence_length++] = rand() % 4 + 1; // Add new number
            round++;                                      // Increment round
            redraw_screen = 1;                            // Redraw for new round
        }
    }

    // Game over
    clearScreen(COLOR_RED);
    drawString5x7(30, 70, "GAME OVER", COLOR_WHITE, COLOR_RED);
}
