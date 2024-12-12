#include <msp430.h>
#include "lcdgame.h"
#include "input.h"
#include "libTimer.h"

void main() {
    configureClocks();       // Initialize system clocks
    lcd_game_init();         // Initialize LCD game
    input_init();            // Initialize input handling

    unsigned int sequence[4] = {1, 2, 3, 4}; // Example sequence
    while (1) {
        int result = input_process(sequence, 4);
        if (result == 1) {
            lcd_game_display_correct();
        } else if (result == 0) {
            lcd_game_display_incorrect();
        }
    }
}
