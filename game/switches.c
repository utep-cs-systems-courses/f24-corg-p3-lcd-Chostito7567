#include "switches.h"
#include <msp430.h>

char switches;

void switch_init() {
    P2REN |= SWITCHES; // Enable resistors for switches
    P2IE |= SWITCHES;  // Enable interrupts from switches
    P2OUT |= SWITCHES; // Pull-ups for switches
    P2DIR &= ~SWITCHES; // Set switches as input
}

void switch_interrupt_handler() {
    switches = P2IN & SWITCHES; // Read switch values
}
