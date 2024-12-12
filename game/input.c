#include <msp430.h>
#include "input.h"
#include "switches.h"

// Global variables to track the input sequence
int current_index = 0;
extern int number_sequence[]; // Array of numbers to match

// Process user inputs
void input_process() {
    if (switches & SW1) { // If SW1 is pressed
        if (number_sequence[current_index] == 1) {
            current_index++; // Correct input, move to the next
        } else {
            current_index = 0; // Reset index on incorrect input
        }
    } else if (switches & SW2) { // If SW2 is pressed
        if (number_sequence[current_index] == 2) {
            current_index++;
        } else {
            current_index = 0;
        }
    } else if (switches & SW3) { // If SW3 is pressed
        if (number_sequence[current_index] == 3) {
            current_index++;
        } else {
            current_index = 0;
        }
    } else if (switches & SW4) { // If SW4 is pressed
        if (number_sequence[current_index] == 4) {
            current_index++;
        } else {
            current_index = 0;
        }
    }
    
    // If all inputs are correct
    if (current_index >= 4) { // Assuming sequence length is 4
        current_index = 0; // Reset for the next round
        lcd_game_generate_sequence(); // Generate new sequence
    }
}
