#include <msp430.h>
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"

int switches = 0;

static char switch_update_interrupt_sense() {
    char p2val = P2IN;
    P2IES |= (p2val & SWITCHES);   // Sense high-to-low
    P2IES &= (p2val | ~SWITCHES);  // Sense low-to-high
    return p2val;
}

void switch_init() {
    P2REN |= SWITCHES;  // Enable resistors for switches
    P2IE |= SWITCHES;   // Enable interrupts from switches
    P2OUT |= SWITCHES;  // Pull-ups for switches
    P2DIR &= ~SWITCHES; // Set switches' bits for input
    switch_update_interrupt_sense();
}

void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();
    switches = ~p2val & SWITCHES; // Update global switches variable

    // Debugging: Display detected switch
    char buffer[16];
    sprintf(buffer, "SW: %d", switches);
    drawString5x7(10, 100, buffer, COLOR_WHITE, COLOR_BLUE);
}
