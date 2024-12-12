#ifndef led_included
#define led_included

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED | LED_GREEN)

void led_init();
void led_update();

extern unsigned char led_changed, green_on, red_on, led_state;

#endif // led_included
