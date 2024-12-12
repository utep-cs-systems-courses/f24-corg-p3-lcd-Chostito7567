#include <stdint.h>
#include <stdio.h>  // For sprintf()
#include "../lcdLib/lcddraw.h"
#include "../lcdLib/lcdutils.h"

// Typedefs for compatibility with lcdLib
typedef unsigned char u_char;
typedef unsigned int u_int;

// Game variables
int lives = 3;  // Number of lives
int score = 0;  // Player's score

// Initializes the game and displays the start screen
void lcd_game_init() {
    clearScreen(COLOR_BLACK);
    drawString5x7(10, 5, "Game Start!", COLOR_WHITE, COLOR_BLACK);
}

// Displays the player's score on the screen
void lcd_display_score() {
    char scoreText[16];
    sprintf(scoreText, "Score: %d", score);
    drawString5x7(10, 20, scoreText, COLOR_WHITE, COLOR_BLACK);
}

// Displays the player's remaining lives on the screen
void lcd_display_lives() {
    char livesText[16];
    sprintf(livesText, "Lives: %d", lives);
    drawString5x7(10, 30, livesText, COLOR_WHITE, COLOR_BLACK);
}

// Displays the current prompt on the screen
void lcd_display_prompt(char prompt) {
    clearScreen(COLOR_BLACK);  // Clear the screen for the next prompt
    lcd_display_score();
    lcd_display_lives();

    if (prompt == 'w') {
        drawString5x7(50, 50, "UP", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == 's') {
        drawString5x7(50, 50, "DOWN", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == 'a') {
        drawString5x7(50, 50, "LEFT", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == 'd') {
        drawString5x7(50, 50, "RIGHT", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == '?') {
        drawString5x7(50, 50, "?", COLOR_RED, COLOR_BLACK);  // Wildcard
    }
}

// Handles correct input
void lcd_correct_input() {
    score++;  // Increment the score
    drawString5x7(10, 40, "Correct!", COLOR_GREEN, COLOR_BLACK);
}

// Handles incorrect input
void lcd_incorrect_input() {
    lives--;  // Decrement lives
    drawString5x7(10, 40, "Incorrect!", COLOR_RED, COLOR_BLACK);
}

// Displays the game-over screen
void lcd_game_over() {
    clearScreen(COLOR_BLACK);
    drawString5x7(30, 50, "GAME OVER", COLOR_RED, COLOR_BLACK);

    char finalScore[16];
    sprintf(finalScore, "Score: %d", score);  // Show final score
    drawString5x7(40, 80, finalScore, COLOR_WHITE, COLOR_BLACK);
}
