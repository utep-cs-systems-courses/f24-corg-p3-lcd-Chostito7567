#include "switches.h"

unsigned int switches; // Define the switches variable

void switch_init() {
    P2REN |= SWITCHES;  // Enable resistors for switches
    P2IE |= SWITCHES;   // Enable interrupts from switches
    P2OUT |= SWITCHES;  // Pull-up resistors for switches
    P2DIR &= ~SWITCHES; // Set switches as inputs
}

void switch_interrupt_handler() {
    switches = P2IN & SWITCHES; // Read switch values
}
