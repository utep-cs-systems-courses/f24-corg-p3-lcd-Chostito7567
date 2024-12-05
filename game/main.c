#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdgame.h"  // Include game logic functions

void main() {
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Initialize Buzzer
    led_init();                 // Initialize LEDs

    // LCD Initialization and Game Start
    lcd_game_init();            // Initialize the LCD for the game
    lcd_game_play();            // Start the game loop

    // Watchdog Timer
    enableWDTInterrupts();      // Enable Watchdog Timer

    // Power off CPU (enters low-power mode)
    or_sr(0x18);
}
