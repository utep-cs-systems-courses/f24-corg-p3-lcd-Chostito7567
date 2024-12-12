#include "input.h"
#include "lcdgame.h"
#include "switches.h"

unsigned int current_color = COLOR_ORANGE; // Default background color

void input_process() {
    if (switches & SW1) {
        current_color = COLOR_GREEN; // S1 -> Green
    } else if (switches & SW2) {
        current_color = COLOR_RED; // S2 -> Red
    } else if (switches & SW3) {
        current_color = COLOR_RED; // S3 -> Red
    } else if (switches & SW4) {
        current_color = COLOR_BLACK; // S4 -> Black
    }
}
