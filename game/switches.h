#ifndef SWITCHES_H
#define SWITCHES_H

#include <msp430.h>

// Define switch macros
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4) // Combine all switches

extern unsigned int switches; // Extern declaration for switches variable

void switch_init();
void switch_interrupt_handler();

#endif // SWITCHES_H
