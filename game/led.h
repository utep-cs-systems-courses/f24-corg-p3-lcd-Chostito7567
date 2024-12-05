#ifndef led_included
#define led_included

#define LED_RED BIT0       // P1.0
#define LED_GREEN BIT6     // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();           /* Initialize LEDs */
void led_update();         /* Update LEDs */
void led_toggle();         /* Toggle LED state */
void led_advance();        /* Advance LED state */

extern unsigned char led_changed, green_on, red_on, led_state;
extern char ledFlags;

#endif // led_included
