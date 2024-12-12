#include <msp430.h>
#include "lcdgame.h"
#include "input.h"
#include "switches.h"
#include "lcdutils.h"

unsigned int sequence[4] = {1, 2, 3, 4};

void main() {
    configureClocks();
    lcd_game_init();
    input_init();
    switch_init();

    enableWDTInterrupts(); // Watchdog timer for periodic tasks

    or_sr(0x18); // CPU off, GIE on
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) { // Check for interrupts from switches
        P2IFG &= ~SWITCHES; // Clear pending flags
        switch_interrupt_handler(); // Handle switches
    }
}

void __interrupt_vec(WDT_VECTOR) WDT() {
    int result = input_process(sequence, 4);
    if (result == 1) {
        lcd_game_display_correct();
    } else if (result == 0) {
        lcd_game_display_incorrect();
    } else {
        lcd_game_display();
    }
}
