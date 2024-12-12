#include <msp430.h>
#include "lcdutils.h"
#include "led.h"
#include "buzzer.h"
#include "input.h"
#include "lcdgame.h"
#include "switches.h"

unsigned int expected_sequence[] = {1, 2, 3, 4}; // Example sequence
#define SEQUENCE_LENGTH 4

void main() {
    WDTCTL = WDTPW | WDTHOLD;     // Stop watchdog timer
    configureClocks();            // Initialize clocks
    lcd_init();                   // Initialize LCD
    led_init();                   // Initialize LEDs
    buzzer_init();                // Initialize buzzer
    switch_init();                // Initialize switches
    lcd_game_init();              // Initialize game screen

    while (1) {
        // Process user inputs
        int result = input_process(expected_sequence, SEQUENCE_LENGTH);

        if (result == 1) { // Correct sequence
            lcd_game_display_correct();
            play_correct_buzzer(); // Play buzzer for correct
            led_green_on();        // Turn on green LED
        } else if (result == 0) { // Incorrect sequence
            lcd_game_display_incorrect();
            play_incorrect_buzzer(); // Play buzzer for incorrect
            led_red_on();            // Turn on red LED
        } else {
            lcd_game_display();      // Show the game screen
        }
    }
}
