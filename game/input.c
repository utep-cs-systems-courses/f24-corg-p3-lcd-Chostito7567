#include "input.h"

// Declare user_input_index globally
static int user_input_index = 0; // Tracks the current index of user input

void input_init() {
    user_input_index = 0; // Initialize user_input_index
}

int input_process(unsigned int *expected_sequence, int sequence_length) {
    // Example logic for processing input
    if (expected_sequence[user_input_index] == 1) {
        // Process button 1
        user_input_index++;
        return 1; // Success
    } else {
        return 0; // Failure
    }
}
