#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"

// Function declarations
void update_led_and_buzzer(u_int switches);

void main() {
  configureClocks();         // Configure system clocks
  lcd_init();                // Initialize the LCD
  switch_init();             // Initialize switches
  buzzer_init();             // Initialize buzzer
  led_init();                // Initialize LEDs

  or_sr(0x8);                // Enable global interrupts (GIE)

  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);   // Clear screen with blue color

  drawString5x7(10, 10, "Switches:", COLOR_GREEN, COLOR_BLUE);

  while (1) {
    u_int switches = p2sw_read(), i;
    char str[5];

    // Update the display to reflect switch states
    for (i = 0; i < 4; i++) {
      str[i] = (switches & (1 << i)) ? '-' : '0' + i;
    }
    str[4] = 0;

    drawString5x7(20, 20, str, COLOR_GREEN, COLOR_BLUE);

    // Update LEDs and buzzer based on switches
    update_led_and_buzzer(switches);
  }
}

// Function to update LEDs and buzzer based on switch states
void update_led_and_buzzer(u_int switches) {
  // If SW1 is pressed, turn on the red LED and play a high-pitched sound
  if (!(switches & SW1)) {
    led_state = 1;            // Set LED state for red
    buzzer_set_period(1000);  // Play a high-pitched sound
  }
  // If SW2 is pressed, turn on the green LED and play a low-pitched sound
  else if (!(switches & SW2)) {
    led_state = 2;            // Set LED state for green
    buzzer_set_period(2000);  // Play a low-pitched sound
  }
  // If SW3 is pressed, turn on both LEDs and play a medium-pitched sound
  else if (!(switches & SW3)) {
    led_state = 3;            // Set LED state for both LEDs
    buzzer_set_period(1500);  // Play a medium-pitched sound
  }
  // If SW4 is pressed, turn off LEDs and stop the buzzer
  else if (!(switches & SW4)) {
    led_state = 0;            // Turn off LEDs
    buzzer_set_period(0);     // Stop the buzzer
  }

  led_update();               // Update the LED states
}
