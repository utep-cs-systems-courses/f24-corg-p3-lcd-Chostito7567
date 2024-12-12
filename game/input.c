#include "input.h"
#include "switches.h" // For the `switches` variable
#include "lcdgame.h"  // For sequence handling
#include <msp430.h>

void input_init() {
    // Initialization logic for input (if needed)
}

int input_process(unsigned int *expected_sequence, int sequence_length) {
    static int input_index = 0;

    if (switches & SW1) {
        if (expected_sequence[input_index] == 1) {
            input_index++;
        } else {
            input_index = 0; // Reset if incorrect
            return 0; // Incorrect input
        }
    } else if (switches & SW2) {
        if (expected_sequence[input_index] == 2) {
            input_index++;
        } else {
            input_index = 0;
            return 0;
        }
    } else if (switches & SW3) {
        if (expected_sequence[input_index] == 3) {
            input_index++;
        } else {
            input_index = 0;
            return 0;
        }
    } else if (switches & SW4) {
        if (expected_sequence[input_index] == 4) {
            input_index++;
        } else {
            input_index = 0;
            return 0;
        }
    }

    if (input_index == sequence_length) {
        input_index = 0;
        return 1; // Sequence complete
    }

    return -1; // In-progress
}
