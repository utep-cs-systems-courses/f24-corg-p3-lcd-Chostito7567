#include <msp430.h>
#include "buzzer.h"

void buzzer_init() {
    P2DIR |= BIT6;
    P2SEL |= BIT6;
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1; // 50% duty cycle
}

void play_correct_buzzer() {
    buzzer_set_period(1000); // Higher pitch
    __delay_cycles(1000000);
    buzzer_set_period(0); // Turn off
}

void play_incorrect_buzzer() {
    buzzer_set_period(500); // Lower pitch
    __delay_cycles(1000000);
    buzzer_set_period(0); // Turn off
}
