#ifndef LCDGAME_H
#define LCDGAME_H

void lcd_game_init();           // Initialize the LCD
void lcd_display_score();       // Display the player's score
void lcd_display_lives();       // Display remaining lives
void lcd_display_prompt(char);  // Display a prompt (e.g., arrows or ?)
void lcd_correct_input();       // Handle correct input
void lcd_incorrect_input();     // Handle incorrect input
void lcd_game_over();           // Display game over screen

#endif // LCDGAME_H
