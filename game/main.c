#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdgame.h"
#include "libTimer.h"

void main() {
    configureClocks();
    switch_init();
    buzzer_init();
    lcd_init();

    enableWDTInterrupts(); // Enable watchdog timer for periodic interrupts
    or_sr(0x18);           // CPU off, GIE on

    lcd_game_play();       // Start the game
}
