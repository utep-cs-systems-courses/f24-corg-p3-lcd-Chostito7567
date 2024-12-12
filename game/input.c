#include <msp430.h>
#include "input.h"
#include "switches.h" // Include to access `switches`

// Process user input
int input_process(unsigned int* expected_sequence, int sequence_length) {
    static int current_index = 0;

    if (switches & SW1) { // If SW1 is pressed
        if (expected_sequence[current_index] == 1) {
            current_index++; // Correct input, move to the next
        } else {
            current_index = 0; // Reset index on incorrect input
            return 0; // Indicate incorrect input
        }
    } else if (switches & SW2) { // If SW2 is pressed
        if (expected_sequence[current_index] == 2) {
            current_index++;
        } else {
            current_index = 0;
            return 0;
        }
    } else if (switches & SW3) { // If SW3 is pressed
        if (expected_sequence[current_index] == 3) {
            current_index++;
        } else {
            current_index = 0;
            return 0;
        }
    } else if (switches & SW4) { // If SW4 is pressed
        if (expected_sequence[current_index] == 4) {
            current_index++;
        } else {
            current_index = 0;
            return 0;
        }
    }

    if (current_index >= sequence_length) {
        current_index = 0; // Reset for the next round
        return 1; // Indicate success
    }

    return -1; // Indicate in-progress
}
