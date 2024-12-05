#include <msp430.h>
#include "switches.h"

int switches = 0;

static char switch_update_interrupt_sense() {
    char p2val = P2IN;
    P2IES |= (p2val & SWITCHES);
    P2IES &= (p2val | ~SWITCHES);
    return p2val;
}

void switch_init() {
    P2REN |= SWITCHES;
    P2IE |= SWITCHES;
    P2OUT |= SWITCHES;
    P2DIR &= ~SWITCHES;
    switch_update_interrupt_sense();
}

void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();
    switches = ~p2val & SWITCHES;
}
