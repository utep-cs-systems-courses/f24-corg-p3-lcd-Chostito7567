#include <msp430.h>
#include "led.h"

unsigned char led_changed = 0, green_on = 0, red_on = 0, led_state = 0;

void led_init() {
    P1DIR |= LEDS;  // Set LED pins as output
    led_changed = 1;
    led_update();
}

void led_update() {
    if (led_changed) {
        char ledFlags = 0;
        if (led_state == 0) {
            ledFlags |= LED_RED;
        } else if (led_state == 1) {
            ledFlags |= LED_GREEN;
        } else if (led_state == 2) {
            ledFlags |= (LED_RED | LED_GREEN);
        }
        P1OUT = (P1OUT & ~LEDS) | ledFlags;
        led_changed = 0;
    }
}
