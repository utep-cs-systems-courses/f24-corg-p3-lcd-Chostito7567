#include <msp430.h>
#include "buzzer.h"

void buzzer_init() {
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR |= BIT6;
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1;
}

void play_jingle1() { buzzer_set_period(1000); __delay_cycles(500000); buzzer_set_period(0); }
void play_jingle2() { buzzer_set_period(800); __delay_cycles(500000); buzzer_set_period(0); }
void play_jingle3() { buzzer_set_period(600); __delay_cycles(500000); buzzer_set_period(0); }
void play_jingle4() { buzzer_set_period(400); __delay_cycles(500000); buzzer_set_period(0); }
