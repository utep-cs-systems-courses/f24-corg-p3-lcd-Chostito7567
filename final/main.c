#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "lcdgame.h"

void main() {
    configureClocks();
    lcd_init();
    lcd_game_init();  // Replace with your custom init function if applicable

    while (1) {
        lcd_game_update();  // Replace with your game logic function
    }
}
