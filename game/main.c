#include <msp430.h>
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "libTimer.h"

void main() {
    configureClocks();
    lcd_init();
    switch_init();
    buzzer_init();

    enableWDTInterrupts();
    or_sr(0x18);  // CPU off, GIE on

    while (1) {
        // Display which switch is pressed
        char buffer[16];
        sprintf(buffer, "SW: %d", switches);
        clearScreen(COLOR_BLUE);
        drawString5x7(10, 100, buffer, COLOR_WHITE, COLOR_BLUE);
        __delay_cycles(500000);
    }
}
