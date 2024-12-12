#include "switches.h"
#include <msp430.h>

char switches = 0;

void switch_init() {
    P2REN |= SWITCHES;  // Enable resistors for switches
    P2IE |= SWITCHES;   // Enable interrupts for switches
    P2OUT |= SWITCHES;  // Pull-up resistors
    P2DIR &= ~SWITCHES; // Set switches as input
    P2IFG &= ~SWITCHES; // Clear pending interrupts
}

void switch_interrupt_handler() {
    switches = P2IN & SWITCHES; // Update switch state
    P2IFG &= ~SWITCHES;         // Clear interrupt flags
}
