#ifndef switches_included
#define switches_included

#include <msp430.h>

#define SWITCHES (SW1 | SW2 | SW3 | SW4)
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

extern unsigned int switches; // Declare the global variable

void switch_init();
void switch_interrupt_handler();

#endif // switches_included
