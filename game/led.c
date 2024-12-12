#include "led.h"
#include <msp430.h>

void led_init() {
    P1DIR |= LEDS; // Set LED pins as output
    led_update(0); // Turn off LEDs
}

void led_update(char led_state) {
    P1OUT = (P1OUT & ~LEDS) | led_state;
}
