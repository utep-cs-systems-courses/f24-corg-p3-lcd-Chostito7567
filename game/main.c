#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdgame.h"
#include "input.h"

void main() {
    configureClocks();          // Start Lib Timer
    switch_init();              // Setup Switches
    buzzer_init();              // Initialize Speakers
    led_init();                 // Initialize LEDs
    lcd_game_init();            // Initialize LCD

    enableWDTInterrupts();      // Enable Watchdog Timer

    or_sr(0x18); // Power off CPU, enable interrupts

    while (1) {
        input_process();        // Process input
        lcd_game_display();     // Update the display
    }
}
