#include <msp430.h>
#include "lcdutils.h"

void clearScreen(u_int color) {
    lcd_setArea(0, 0, screenWidth - 1, screenHeight - 1);
    for (int i = 0; i < screenWidth * screenHeight; i++) {
        lcd_writeColor(color);
    }
}

int main() {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    lcd_init();               // Initialize the LCD
    clearScreen(COLOR_BLACK); // Clear screen to black

    lcd_setArea(30, 30, 60, 60); // Draw a green square
    for (int i = 0; i < 900; i++) {
        lcd_writeColor(COLOR_GREEN);
    }

    while (1);
}
