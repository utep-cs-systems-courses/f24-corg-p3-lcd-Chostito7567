#include "input.h"
#include "switches.h"

int input_process(unsigned int *expected_sequence, int sequence_length) {
    static int user_input_index = 0;

    if (switches & SW1) {
        if (expected_sequence[user_input_index++] != 1) {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW2) {
        if (expected_sequence[user_input_index++] != 2) {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW3) {
        if (expected_sequence[user_input_index++] != 3) {
            user_input_index = 0;
            return 0;
        }
    } else if (switches & SW4) {
        if (expected_sequence[user_input_index++] != 4) {
            user_input_index = 0;
            return 0;
        }
    }

    if (user_input_index == sequence_length) {
        user_input_index = 0;
        return 1; // Success
    }

    return -1; // Waiting for input
}
