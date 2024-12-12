
#include "lcdgame.h"
#include "input.h"
#include "switches.h"

// Process user input to check against the expected sequence
int input_process(unsigned int *expected_sequence, int sequence_length) {
    static int user_input_index = 0; // Tracks current position in the sequence

    if (switches & SW1) { // If Switch 1 is pressed
        if (expected_sequence[user_input_index] != 1) {
            user_input_index = 0; // Reset on incorrect input
            return 0; // Incorrect
        }
        user_input_index++;
    } else if (switches & SW2) { // If Switch 2 is pressed
        if (expected_sequence[user_input_index] != 2) {
            user_input_index = 0;
            return 0;
        }
        user_input_index++;
    } else if (switches & SW3) { // If Switch 3 is pressed
        if (expected_sequence[user_input_index] != 3) {
            user_input_index = 0;
            return 0;
        }
        user_input_index++;
    } else if (switches & SW4) { // If Switch 4 is pressed
        if (expected_sequence[user_input_index] != 4) {
            user_input_index = 0;
            return 0;
        }
        user_input_index++;
    }

    if (user_input_index >= sequence_length) {
        user_input_index = 0; // Reset index on correct completion
        return 1; // Sequence completed correctly
    }

    return -1; // Input is ongoing
}
