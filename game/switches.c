#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

// Global variable for switches
int switches = 0;

char switch_state_down, switch_state_changed;

// Internal function to update switch interrupt sense
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

    switches = ~p2val & SWITCHES; // Update global switches variable

    if (switches & SW1) {
        play_jingle1();
        led_state = 0;
    } else if (switches & SW2) {
        play_jingle2();
        led_state = 1;
    } else if (switches & SW3) {
        play_jingle3();
        led_state = 2;
    } else if (switches & SW4) {
        play_jingle4();
        led_state = 3;
    }

    // Indicate that a switch has changed state
    switch_state_changed = 1;

    led_changed = 1;
    led_update();
}

// Helper function to check if a specific switch is pressed
int is_switch_pressed(int switch_mask) {
    return switches & switch_mask;
}
