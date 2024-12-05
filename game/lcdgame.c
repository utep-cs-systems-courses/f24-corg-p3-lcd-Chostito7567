void lcd_game_play() {
    while (lives > 0) {
        display_sequence(); // Show the sequence

        // Wait for user input
        user_input_index = 0;
        while (user_input_index < sequence_length) {
            if (switches & SW1) {
                play_jingle(1);
                if (sequence[user_input_index++] != 1) {
                    lives--; // Lose a life on incorrect input
                    break;
                }
            } else if (switches & SW2) {
                play_jingle(2);
                if (sequence[user_input_index++] != 2) {
                    lives--;
                    break;
                }
            } else if (switches & SW3) {
                play_jingle(3);
                if (sequence[user_input_index++] != 3) {
                    lives--;
                    break;
                }
            } else if (switches & SW4) {
                play_jingle(4);
                if (sequence[user_input_index++] != 4) {
                    lives--;
                    break;
                }
            }
            __delay_cycles(300000); // Debounce delay
        }

        if (lives > 0 && user_input_index == sequence_length) {
            sequence[sequence_length++] = rand() % 4 + 1; // Add new number
            round++;                                      // Increment round
        }
    }

    // Game over
    clearScreen(COLOR_RED);
    drawString5x7(30, 70, "GAME OVER", COLOR_WHITE, COLOR_RED);
}
