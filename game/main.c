#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdgame.h"  // Include lcdgame for LCD functions

void main()
{
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs

    // LCD Initialization
    lcd_game_init();            // Initialize the LCD
    lcd_draw_square();          // Draw a square on the LCD

    // Watchdog
    enableWDTInterrupts();      // Enable Watchdog Timer

    // Power off CPU
    or_sr(0x18);
}
