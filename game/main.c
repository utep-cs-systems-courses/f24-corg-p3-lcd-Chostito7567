#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdgame.h"

void main() {
    configureClocks();          // Start Lib Timer
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs

    lcd_game_init();            // Initialize LCD game

    enableWDTInterrupts();      // Enable Watchdog Timer

    while (1) {
        lcd_game_display();     // Continuously display game logic
    }
}
