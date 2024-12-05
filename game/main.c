#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdgame.h"

void update_shape(); // Original functionality

void main() {
    P1DIR |= BIT6;              /**< Green LED on when CPU on */
    P1OUT |= BIT6;

    configureClocks();          // Set up system clocks
    lcd_game_init();            // Initialize the LCD
    switch_init();              // Initialize switches

    enableWDTInterrupts();      // Enable periodic interrupts
    or_sr(0x8);                 // Enable global interrupts

    clearScreen(COLOR_BLUE);    // Clear screen to blue

    lcd_draw_square();          // Draw a static square

    while (1) {                 // Main loop
        if (redrawScreen) {     // Check if the screen needs an update
            redrawScreen = 0;
            update_shape();     // Original functionality
        }
        P1OUT &= ~BIT6;         // Turn off LED
        or_sr(0x10);            // CPU OFF
        P1OUT |= BIT6;          // Turn on LED
    }
}
