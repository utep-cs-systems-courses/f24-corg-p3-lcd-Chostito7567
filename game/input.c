#include "input.h"
#include "buzzer.h"
#include "led.h"
#include <msp430.h>

static unsigned int user_input[4];  // Array to store the user's inputs
static int input_index = 0;         // Index to track user input progress
static int sequence_match = 1;      // Flag to indicate sequence correctness

void input_init() {
    input_index = 0;
    sequence_match = 1;  // Reset sequence match status
    for (int i = 0; i < 4; i++) {
        user_input[i] = 0;
    }
}

int input_process(unsigned int* expected_sequence, int sequence_length) {
    char p2val = P2IN;  // Read button inputs

    // Detect button presses
    if (!(p2val & SW1)) {
        user_input[input_index++] = 1;
    } else
