#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdgame.h"  // Include the lcdgame header for new functionality

void main() {
    configureClocks();        // Start Lib Timer
    lcd_init();               // Initialize the LCD
    clearScreen(COLOR_BLUE);  // Clear screen to blue

    lcd_game_display();       // Add this call to display the square and random numbers

    or_sr(0x18);              // Keep CPU off, GIE on
}
