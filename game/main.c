#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "stateMachines.h"

void main() {
    configureClocks();  // Set up the clock system
    led_init();         // Initialize LEDs
    buzzer_init();      // Initialize buzzer
    switch_init();      // Initialize switches

    enableWDTInterrupts(); // Enable Watchdog Timer for state machine
    or_sr(0x18);           // CPU off, GIE on
}
