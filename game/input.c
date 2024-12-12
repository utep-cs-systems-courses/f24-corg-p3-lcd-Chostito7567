#include "input.h"
#include "switches.h"

// Global variables
unsigned int user_input[4];
unsigned int user_input_index = 0;

void input_init() {
    user_input_index = 0; // Reset user input index
}

int input_process(unsigned int *expected_sequence, int sequence_length) {
    if (switches & SW1) { // If SW1 is pressed
        user_input[user_input_index++] = 1;
    } else if (switches & SW2) { // If SW2 is pressed
        user_input[user_input_index++] = 2;
    } else if (switches & SW3) { // If SW3 is pressed
        user_input[user_input_index++] = 3;
    } else if (switches & SW4) { // If SW4 is pressed
        user_input[user_input_index++] = 4;
    }

    // Check if the user input matches the expected sequence
    if (user_input_index == sequence_length) {
        for (int i = 0; i < sequence_length; i++) {
            if (user_input[i] != expected_sequence[i]) {
                return -1; // Incorrect sequence
            }
        }
        return 1; // Correct sequence
    }

    return 0; // Still waiting for input
}
