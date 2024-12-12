#include <msp430.h>
#include "led.h"

void led_init() {
    P1DIR |= BIT0 | BIT6; // Set LED pins as outputs
    P1OUT &= ~(BIT0 | BIT6); // Turn LEDs off initially
}

void led_red_on() {
    P1OUT = (P1OUT & ~BIT6) | BIT0; // Turn on red LED, turn off green
}

void led_green_on() {
    P1OUT = (P1OUT & ~BIT0) | BIT6; // Turn on green LED, turn off red
}
