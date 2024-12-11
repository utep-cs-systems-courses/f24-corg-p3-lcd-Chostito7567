#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense() {
    char p2val = P2IN;
    P2IES |= (p2val & SWITCHES);   // Sense high-to-low
    P2IES &= (p2val | ~SWITCHES);  // Sense low-to-high
    return p2val;
}

void switch_init() {
    P2REN |= SWITCHES;  // Enable resistors for switches
    P2IE |= SWITCHES;   // Enable interrupts from switches
    P2OUT |= SWITCHES;  // Pull-ups for switches
    P2DIR &= ~SWITCHES; // Set switches' bits for input
    switch_update_interrupt_sense();
}

void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();

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
