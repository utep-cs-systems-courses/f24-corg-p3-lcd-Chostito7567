#include "lcdgame.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "input.h"

static unsigned int sequence[4] = {1, 2, 3, 4};  // Example sequence
static int sequence_length = 4;  // Fixed length for now

void lcd_game_init() {
    lcd_init();
    clearScreen(COLOR_BLUE);
    input_init();  // Initialize input system
}

void lcd_game_display() {
    clearScreen(COLOR_ORANGE);
    lcd_draw_square();  // Draw the square

    // Display the sequence numbers inside the square
    for (int i = 0; i < sequence_length; i++) {
        char num = sequence[i] + '0';  // Convert to ASCII
        drawChar5x7(30 + (i * 10), 70, num, COLOR_WHITE, COLOR_ORANGE);
    }

    // Wait for user input
    int result = input_process(sequence, sequence_length);

    if (result == 1) {
        drawString5x7(30, 90, "Correct!", COLOR_GREEN, COLOR_ORANGE);
        // Generate new random sequence
        for (int i = 0; i < sequence_length; i++) {
            sequence[i] = (rand() % 4) + 1;
        }
    } else if (result == -1) {
        drawString5x7(30, 90, "Incorrect!", COLOR_RED, COLOR_ORANGE);
        // Reset the sequence for simplicity
    }
}

void lcd_draw_square() {
    fillRectangle(20, 60, 100, 40, COLOR_ORANGE);
}
