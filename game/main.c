#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdgame.h"

void main()
{
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs

    // LCD
    lcd_game_init();            // Initialize the LCD

    // Watchdog
    enableWDTInterrupts();      // Enable Watchdog Timer

    while (1) {
        lcd_draw_square();      // Draw the orange square
        lcd_game_display();     // Display the random array of numbers
        __delay_cycles(1000000); // Delay for a second to observe changes
    }
}
