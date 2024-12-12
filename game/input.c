#include "input.h"
#include "switches.h" // For the `switches` variable
#include "lcdgame.h"  // For sequence handling
#include <msp430.h>

extern int switches;

void input_init() {
    // Initialization logic for input (if needed)
}

int input_process(unsigned int *expected_sequence, int sequence_length) {
    static int input_index = 0;

    if (switches & SW1) { // If SW1 is pressed
        if (expected_sequence[user_input_index] == 1) {
            user_input_index++;
        } else {
            user_input_index = 0; // Reset on incorrect input
            return 0; // Incorrect
        }
    } else if (switches & SW2) {
        if (expected_sequence[user_input_index] == 2) {
            user_input_index++;
        } else {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW3) {
        if (expected_sequence[user_input_index] == 3) {
            user_input_index++;
        } else {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW4) {
        if (expected_sequence[user_input_index] == 4) {
            user_input_index++;
        } else {
            user_input_index = 0;
            return 0;
        }
    }

    if (user_input_index == sequence_length) {
        user_input_index = 0; // Reset after successful input
        return 1; // Correct
    }

    return -1; // Waiting for input
}
