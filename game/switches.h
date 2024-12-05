#ifndef SWITCHES_H
#define SWITCHES_H

#include <msp430.h> // Ensure this is included

// Define switch pins
#define SW1 BIT0 // Switch 1 connected to BIT0
#define SW2 BIT1 // Switch 2 connected to BIT1
#define SW3 BIT2 // Switch 3 connected to BIT2
#define SW4 BIT3 // Switch 4 connected to BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

// Declare global variable for switches
extern int switches;

// Function prototypes
void switch_init();
void switch_interrupt_handler();

#endif // SWITCHES_H
