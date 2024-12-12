#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char current_sequence[] = {1, 2, 3, 4}; // Example sequence
int sequence_index = 0;
int user_index = 0;

void play_sequence() {
    // Play the current sequence (using LEDs and buzzer)
    for (int i = 0; i <= sequence_index; i++) {
        if (current_sequence[i] == 1) {
            led_update(LED_RED);
            buzzer_set_period(1000);
        } else if (current_sequence[i] == 2) {
            led_update(LED_GREEN);
            buzzer_set_period(1500);
        } else if (current_sequence[i] == 3) {
            led_update(LED_BLUE);
            buzzer_set_period(2000);
        } else if (current_sequence[i] == 4) {
            led_update(LED_YELLOW);
            buzzer_set_period(2500);
        }
        __delay_cycles(500000); // Wait
        led_update(0);          // Turn off LED
        buzzer_set_period(0);   // Turn off buzzer
        __delay_cycles(250000); // Short pause
    }
    sequence_index++; // Increment sequence length
}

void check_input() {
    // Check if the user's input matches the sequence
    if ((switches & SW1 && current_sequence[user_index] == 1) ||
        (switches & SW2 && current_sequence[user_index] == 2) ||
        (switches & SW3 && current_sequence[user_index] == 3) ||
        (switches & SW4 && current_sequence[user_index] == 4)) {
        user_index++; // Correct input, move to the next
        if (user_index > sequence_index) { // Completed sequence
            play_sequence();
            user_index = 0;
        }
    } else if (switches) {
        // Incorrect input, reset game
        buzzer_set_period(500); // Error sound
        __delay_cycles(1000000);
        buzzer_set_period(0);
        sequence_index = 0; // Restart sequence
        user_index = 0;
    }
}
