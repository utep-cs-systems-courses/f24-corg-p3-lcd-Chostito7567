#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdutils.h"  // Add this for LCD functionality
#include "lcddraw.h"   // Add this for drawing shapes
#include "lcdgame.h"   // Include lcdgame for the new feature

void main()
{
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs

    // Initialize LCD
    lcd_init();                 // Initialize the LCD
    clearScreen(COLOR_BLUE);    // Clear the screen to blue

    // Display the square and numbers
    lcd_game_display();         // Add this function to display the square and random numbers

    // Watchdog
    enableWDTInterrupts();      // Enable Watchdog Timer

    // Power off CPU
    or_sr(0x18);
}
