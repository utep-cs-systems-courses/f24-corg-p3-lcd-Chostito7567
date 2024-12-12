#include <msp430.h>
#include "buzzer.h"

void buzzer_init() {
    timerAUpmode();                  // Initialize Timer A
    P2SEL2 &= ~(BIT6 | BIT7);        // Configure P2.6 as output
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR |= BIT6;
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1;              // 50% duty cycle
}
