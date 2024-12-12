#include <msp430.h>
#include "led.h"
#include "lcdgame.h"
#include "input.h"

unsigned int expected_sequence[] = {1, 2, 3, 4}; // Example sequence
int sequence_length = sizeof(expected_sequence) / sizeof(expected_sequence[0]);

void main() {
    // Initialization code (clocks, switches, etc.)
    configureClocks();   // Setup clock system
    led_init();          // Initialize LEDs
    lcd_game_init();     // Initialize LCD
    input_init();        // Initialize inputs

    while (1) {
        int result = input_process(expected_sequence, sequence_length); // Process input

        if (result == 1) {
            // Correct input
            lcd_game_display_correct(); // Function to display correct message (you can define it)
        } else if (result == 0) {
            // Incorrect input
            lcd_game_display_incorrect(); // Function to display incorrect message (you can define it)
        }
    }
}
