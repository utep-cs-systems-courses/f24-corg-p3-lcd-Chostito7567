#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdgame.h"

void lcd_game_init() {
    clearScreen(COLOR_BLACK); // Initialize the screen to black
}

void lcd_game_display() {
    clearScreen(COLOR_BLACK); // Clear the screen
    drawChar5x7(10, 20, '1', COLOR_GREEN, COLOR_BLACK); // Display numbers
    drawChar5x7(30, 20, '2', COLOR_GREEN, COLOR_BLACK);
    drawChar5x7(50, 20, '3', COLOR_GREEN, COLOR_BLACK);
    drawChar5x7(70, 20, '4', COLOR_GREEN, COLOR_BLACK);
}

void lcd_game_display_correct() {
    clearScreen(COLOR_GREEN); // Display green on success
}

void lcd_game_display_incorrect() {
    clearScreen(COLOR_RED); // Display red on failure
}
