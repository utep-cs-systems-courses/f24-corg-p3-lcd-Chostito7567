#include <msp430.h>
#ifndef SWITCHES_H
#define SWITCHES_H

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

extern unsigned int switches;

void switch_init();

#endif // SWITCHES_H
