#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

void main() {
  configureClocks();
  lcd_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts(); // Enable periodic interrupts
  or_sr(0x8);            // Enable global interrupts

  // Call the screen function
  screen();
}
