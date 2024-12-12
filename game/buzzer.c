#include "buzzer.h"
#include <msp430.h>

void buzzer_init() {
    P2DIR |= BIT6; // Set P2.6 as output
    P2SEL |= BIT6; // Select P2.6 for timer
    buzzer_set_period(0);
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1; // 50% duty cycle
}
