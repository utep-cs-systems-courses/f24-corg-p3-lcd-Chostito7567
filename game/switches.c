#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

// Add this line to define the global variable
int switches = 0; 

void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();

    // Add this line to update the global switches variable
    switches = ~p2val & SWITCHES;

    if (!(p2val & SW1)) {
        play_jingle1();
        led_state = 0;
    } else if (!(p2val & SW2)) {
        play_jingle2();
        led_state = 1;
    } else if (!(p2val & SW3)) {
        play_jingle3();
        led_state = 2;
    } else if (!(p2val & SW4)) {
        play_jingle4();
        led_state = 3;
    }
    led_changed = 1;
    led_update();
}
