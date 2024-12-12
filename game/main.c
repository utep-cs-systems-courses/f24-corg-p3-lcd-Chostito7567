#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"

void main() {
    configureClocks();         // Start Lib Timer
    switch_init();             // Initialize switches
    buzzer_init();             // Initialize buzzer
    led_init();                // Initialize LEDs
    enableWDTInterrupts();     // Enable Watchdog Timer
    or_sr(0x18);               // CPU off, GIE on
}
