#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "switches.h"

extern unsigned int switches; // Ensure this matches your existing global variable for switch states

void screen() {
  configureClocks();
  lcd_init();
  or_sr(0x8); // Enable global interrupts
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawString5x7(10, 10, "switches:", COLOR_GREEN, COLOR_BLUE);

  while (1) {
    char str[5];
    for (int i = 0; i < 4; i++) {
      str[i] = (switches & (1 << i)) ? '-' : '0' + i; // Use `switches` directly
    }
    str[4] = 0;
    drawString5x7(20, 20, str, COLOR_GREEN, COLOR_BLUE);
  }
}
