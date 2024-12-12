#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "input.h"
#include "switches.h"

static unsigned int sequence[4];
static int state = 0; // 0: Show sequence, 1: Wait for input, 2: Display result
static int result = -1; // -1: Waiting, 0: Incorrect, 1: Correct

void lcd_game_init() {
    srand(TA0R); // Use Timer A register for randomness
    for (int i = 0; i < 4; i++) {
        sequence[i] = (rand() % 4) + 1; // Random number between 1 and 4
    }
    clearScreen(COLOR_BLUE); // Set screen background
}

void lcd_game_display() {
    static int sequence_index = 0;

    switch (state) {
        case 0: // Display Sequence
            if (sequence_index < 4) {
                char number[2];
                number[0] = '0' + sequence[sequence_index];
                number[1] = '\0';
                drawString5x7(50, 70, number, COLOR_WHITE, COLOR_ORANGE);
                sequence_index++;
                __delay_cycles(1000000); // Delay for visibility
            } else {
                clearScreen(COLOR_BLUE);
                sequence_index = 0;
                state = 1;
            }
            break;

        case 1: // Wait for Input
            result = input_process(sequence, 4);
            if (result != -1) { // If result is determined
                state = 2;
            }
            break;

        case 2: // Display Result
            if (result == 1) {
                drawString5x7(30, 70, "Correct!", COLOR_GREEN, COLOR_BLUE);
            } else {
                drawString5x7(30, 70, "Incorrect!", COLOR_RED, COLOR_BLUE);
            }
            __delay_cycles(2000000); // Wait for a moment
            clearScreen(COLOR_BLUE);
            lcd_game_init(); // Reinitialize game for new round
            state = 0; // Reset to display sequence again
            break;
    }
}
