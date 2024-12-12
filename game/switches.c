#include <msp430.h>
#include "switches.h"

unsigned int switches;

void switch_init() {
    P2DIR &= ~(SW1 | SW2 | SW3 | SW4); // Set switches as inputs
    P2REN |= SW1 | SW2 | SW3 | SW4;    // Enable resistors
    P2OUT |= SW1 | SW2 | SW3 | SW4;    // Set resistors to pull up
    P2IE |= SW1 | SW2 | SW3 | SW4;     // Enable interrupts
    P2IES |= SW1 | SW2 | SW3 | SW4;    // Trigger on falling edge
    P2IFG &= ~(SW1 | SW2 | SW3 | SW4); // Clear interrupt flags
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
    switches = P2IFG & (SW1 | SW2 | SW3 | SW4); // Record which switch was pressed
    P2IFG &= ~(SW1 | SW2 | SW3 | SW4);          // Clear interrupt flags
}
