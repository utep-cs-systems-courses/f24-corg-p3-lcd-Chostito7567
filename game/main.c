#include <msp430.h>
#include "lcdgame.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"

void main() {
    configureClocks();  // Configure system clocks
    lcd_init();         // Initialize LCD
    switch_init();      // Initialize switches
    buzzer_init();      // Initialize buzzer

    lcd_game_play();    // Start the game

    or_sr(0x18);        // Power off CPU (low power mode)
}
