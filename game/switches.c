#include <msp430.h>
#include "switches.h"

unsigned int switches;

void switch_init() {
  P2REN |= SWITCHES;          // Enable resistors for switches
  P2OUT |= SWITCHES;          // Pull-up resistors
  P2DIR &= ~SWITCHES;         // Set as input
  P2IE |= SWITCHES;           // Enable interrupts
  P2IES |= SWITCHES;          // Trigger on high-to-low transition
  P2IFG &= ~SWITCHES;         // Clear interrupt flags
}

void switch_interrupt_handler() {
  switches = P2IN & SWITCHES; // Read switch values
  P2IFG &= ~SWITCHES;         // Clear interrupt flags
}
