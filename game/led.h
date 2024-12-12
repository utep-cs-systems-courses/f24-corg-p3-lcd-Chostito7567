#ifndef LED_H
#define LED_H

#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LED_BLUE BIT1
#define LED_YELLOW BIT2
#define LEDS (LED_RED | LED_GREEN | LED_BLUE | LED_YELLOW)

void led_init();
void led_update(char led_state);

#endif // LED_H
