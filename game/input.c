#include "lcdgame.h"
#include "input.h"
#include "switches.h"

// Function definition for processing user input
int input_process(unsigned int *expected_sequence, int sequence_length) {
    static int user_input_index = 0; // Tracks the current position in the sequence

    // Check which switch was pressed
    if (switches & SW1) { // If SW1 is pressed
        if (expected_sequence[user_input_index++] != 1) {
            user_input_index = 0; // Reset on incorrect input
            return 0;             // Return "incorrect"
        }
    } else if (switches & SW2) { // If SW2 is pressed
        if (expected_sequence[user_input_index++] != 2) {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW3) { // If SW3 is pressed
        if (expected_sequence[user_input_index++] != 3) {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW4) { // If SW4 is pressed
        if (expected_sequence[user_input_index++] != 4) {
            user_input_index = 0;
            return 0;
        }
    }

    // Check if the entire sequence was successfully input
    if (user_input_index == sequence_length) {
        user_input_index = 0; // Reset for the next round
        return 1;             // Return "correct"
    }

    return -1; // Return "still waiting for input"
}
