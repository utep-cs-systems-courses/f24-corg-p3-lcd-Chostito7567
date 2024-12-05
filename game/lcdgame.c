#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"
#include <stdlib.h>
#include <stdio.h>

// Define states
typedef enum {
    INIT,
    START,
    SHOW_SEQUENCE,
    WAIT_INPUT,
    NEXT_ROUND,
    GAME_OVER
} GameState;

// Global variables
GameState current_state = INIT;
static int sequence[10];  // Store the sequence
static int sequence_length = 0;
static int user_input_index = 0;
static int lives = 3;
static int round = 1;
static int current_step = 0;

void lcd_game_play() {
    while (1) {
        switch (current_state) {
            case INIT: state_init(); break;
            case START: state_start(); break;
            case SHOW_SEQUENCE: state_show_sequence(); break;
            case WAIT_INPUT: state_wait_input(); break;
            case NEXT_ROUND: state_next_round(); break;
            case GAME_OVER: state_game_over(); break;
        }
    }
}

void state_init() {
    clearScreen(COLOR_BLUE);
    drawString5x7(10, 10, "STATE: INIT", COLOR_WHITE, COLOR_BLUE);
    __delay_cycles(2000000);

    srand(1234);  // Seed random number generator
    lives = 3;
    round = 1;
    sequence_length = 1;
    sequence[0] = rand() % 4 + 1;
    current_state = START;
}

void state_start() {
    clearScreen(COLOR_BLUE);

    // Display lives and round
    char buffer[16];
    sprintf(buffer, "Lives: %d", lives);
    drawString5x7(5, 5, buffer, COLOR_WHITE, COLOR_BLUE);
    sprintf(buffer, "Round: %d", round);
    drawString5x7(screenWidth - 50, 5, buffer, COLOR_WHITE, COLOR_BLUE);

    __delay_cycles(2000000); // Delay before transitioning
    current_step = 0;        // Reset step counter
    current_state = SHOW_SEQUENCE;
}

void state_show_sequence() {
    if (current_step < sequence_length) {
        clearScreen(COLOR_BLUE);
        
        // Display the current number
        char num[2];
        sprintf(num, "%d", sequence[current_step]);
        drawString5x7(screenWidth / 2 - 5, screenHeight / 2, num, COLOR_WHITE, COLOR_BLUE);

        // Play corresponding jingle
        switch (sequence[current_step]) {
            case 1: play_jingle1(); break;
            case 2: play_jingle2(); break;
            case 3: play_jingle3(); break;
            case 4: play_jingle4(); break;
        }

        __delay_cycles(2000000); // Delay between steps
        current_step++;
    } else {
        // Transition to WAIT_INPUT after showing sequence
        current_state = WAIT_INPUT;
        user_input_index = 0; // Reset user input index
        clearScreen(COLOR_BLUE);
    }
}

void state_wait_input() {
    // Display waiting state
    drawString5x7(10, 10, "STATE: WAIT_INPUT", COLOR_WHITE, COLOR_BLUE);

    if (switches & SW1) {
        play_jingle1();
        if (sequence[user_input_index++] != 1) {
            lives--; // Lose a life if input is incorrect
        }
    } else if (switches & SW2) {
        play_jingle2();
        if (sequence[user_input_index++] != 2) {
            lives--;
        }
    } else if (switches & SW3) {
        play_jingle3();
        if (sequence[user_input_index++] != 3) {
            lives--;
        }
    } else if (switches & SW4) {
        play_jingle4();
        if (sequence[user_input_index++] != 4) {
            lives--;
        }
    }

    // Check for game over
    if (lives <= 0) {
        current_state = GAME_OVER;
        return;
    }

    // If user completes sequence correctly, transition to NEXT_ROUND
    if (user_input_index == sequence_length) {
        current_state = NEXT_ROUND;
    }
}

void state_next_round() {
    clearScreen(COLOR_BLUE);
    drawString5x7(10, 10, "STATE: NEXT_ROUND", COLOR_WHITE, COLOR_BLUE);

    sequence[sequence_length++] = rand() % 4 + 1; // Add new number to sequence
    round++;
    current_state = START;
}

void state_game_over() {
    clearScreen(COLOR_RED);
    drawString5x7(30, 70, "GAME OVER", COLOR_WHITE, COLOR_RED);
    while (1); // Halt execution
}
