#include "lcdutils.h"
#include "lcdgame.h"

void lcd_game_init() {
    clearScreen(COLOR_BLACK); // Start with a black screen
}

void lcd_game_display() {
    clearScreen(COLOR_BLACK);
    drawChar5x7(30, 50, '1', COLOR_GREEN, COLOR_BLACK); // Display random number
    drawChar5x7(50, 50, '2', COLOR_RED, COLOR_BLACK);
    drawChar5x7(70, 50, '3', COLOR_BLUE, COLOR_BLACK);
    drawChar5x7(90, 50, '4', COLOR_ORANGE, COLOR_BLACK);
}

void lcd_game_display_correct() {
    clearScreen(COLOR_GREEN); // Full green for correct input
}

void lcd_game_display_incorrect() {
    clearScreen(COLOR_RED); // Full red for incorrect input
}
