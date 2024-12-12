#ifndef SWITCHES_INCLUDED
#define SWITCHES_INCLUDED
#include <msp430.h>

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

// Global variable for switches
extern unsigned int switches;

void switch_init(); // Initialize switches
void switch_interrupt_handler(); // Handle switch interrupts

#endif // SWITCHES_INCLUDED
