#include <msp430.h>
#include "led.h"

unsigned char led_changed = 0, green_on = 0, red_on = 0, led_state = 0;

void led_init() {
    P1DIR |= LEDS; // Set LED pins as output
    led_changed = 1;
    led_update();
}

void led_update() {
    if (led_changed) {
        switch (led_state) {
        case 0:
            P1OUT = LED_RED; // Only red LED on
            break;
        case 1:
            P1OUT = LED_GREEN; // Only green LED on
            break;
        case 2:
            P1OUT = LEDS; // Both LEDs on
            break;
        case 3:
            P1OUT = 0; // Both LEDs off
            break;
        }
        led_changed = 0;
    }
}
