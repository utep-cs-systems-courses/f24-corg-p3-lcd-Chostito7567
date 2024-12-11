#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdgame.h"
#include "libTimer.h"

void main()
{
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs
    lcd_game_init();            // Initialize LCD game

    lcd_game_display();         // Display the square with random numbers

    // Watchdog
    enableWDTInterrupts();      // Enable Watchdog Timer

    // Power off CPU
    or_sr(0x18);
}
