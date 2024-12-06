#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

// Game-specific definitions
#define MAX_SEQUENCE_LENGTH 9
#define BUTTON_MASK (BIT0 | BIT1 | BIT2 | BIT3) // Example for buttons
#define LED_MASK (BIT4 | BIT5 | BIT6 | BIT7)   // Example for LEDs
#define START_BUTTON BIT0                      // Example start button pin

// Colors
#define BACKGROUND_COLOR COLOR_BLACK
#define LED_ON_COLOR COLOR_GREEN
#define LED_OFF_COLOR COLOR_GRAY
#define TEXT_COLOR COLOR_WHITE

// Global variables
unsigned int sequence[MAX_SEQUENCE_LENGTH];
unsigned int current_step = 0;
unsigned int player_step = 0;

// Function prototypes
void init_peripherals();
void generate_sequence();
void play_sequence();
void check_input(unsigned int button);
void show_message(const char *message);
void play_tone(unsigned int frequency, unsigned int duration);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    init_peripherals();
    lcd_init();

    // Display welcome message
    clearScreen(BACKGROUND_COLOR);
    show_message("Welcome to Simon");

    while (1) {
        // Wait for start button press
        if (!(P1IN & START_BUTTON)) {
            clearScreen(BACKGROUND_COLOR);
            show_message("Game Start!");

            __delay_cycles(1000000); // 1-second delay
            generate_sequence();
            play_sequence();

            // Game loop
            player_step = 0;
            while (player_step < current_step) {
                // Poll for button presses
                if (!(P2IN & BUTTON_MASK)) {
                    unsigned int button = P2IN & BUTTON_MASK;
                    check_input(button);
                }
            }

            // Check win/lose condition
            if (current_step == MAX_SEQUENCE_LENGTH) {
                clearScreen(BACKGROUND_COLOR);
                show_message("You Win!");
            } else {
                clearScreen(BACKGROUND_COLOR);
                show_message("You Lose!");
            }

            __delay_cycles(2000000); // 2-second delay
        }
    }
}

void init_peripherals() {
    // Configure LEDs as outputs
    P1DIR |= LED_MASK;
    P1OUT &= ~LED_MASK;

    // Configure buttons as inputs with pull-up resistors
    P2DIR &= ~BUTTON_MASK;
    P2REN |= BUTTON_MASK;
    P2OUT |= BUTTON_MASK;

    // Configure start button
    P1DIR &= ~START_BUTTON;
    P1REN |= START_BUTTON;
    P1OUT |= START_BUTTON;

    // Configure buzzer (e.g., P2.6)
    P2DIR |= BIT6;
    P2OUT &= ~BIT6;
}

void generate_sequence() {
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        sequence[i] = rand() % 4; // Randomly choose 0-3 for four buttons
    }
    current_step = 1; // Start with one step
}

void play_sequence() {
    for (int i = 0; i < current_step; i++) {
        P1OUT |= (1 << sequence[i]); // Turn on corresponding LED
        fillRectangle(10 + sequence[i] * 30, 50, 20, 20, LED_ON_COLOR);
        play_tone(1000 + 200 * sequence[i], 500); // Play corresponding tone
        __delay_cycles(1000000);                 // 1-second delay
        P1OUT &= ~(1 << sequence[i]);            // Turn off LED
        fillRectangle(10 + sequence[i] * 30, 50, 20, 20, LED_OFF_COLOR);
        __delay_cycles(500000);                  // 0.5-second delay
    }
}

void check_input(unsigned int button) {
    unsigned int pressed = 0;

    // Determine which button was pressed
    if (!(P2IN & BIT0)) pressed = 0;
    else if (!(P2IN & BIT1)) pressed = 1;
    else if (!(P2IN & BIT2)) pressed = 2;
    else if (!(P2IN & BIT3)) pressed = 3;

    // Validate the player's input
    if (pressed == sequence[player_step]) {
        play_tone(1000 + 200 * pressed, 200); // Play feedback tone
        player_step++;
        if (player_step == current_step) {
            current_step++;
            play_sequence(); // Move to the next sequence
            player_step = 0;
        }
    } else {
        // Incorrect input
        clearScreen(BACKGROUND_COLOR);
        show_message("Wrong!");
        current_step = 0; // Reset the game
    }
}

void show_message(const char *message) {
    drawString5x7(10, 10, (char *)message, TEXT_COLOR, BACKGROUND_COLOR);
}

void play_tone(unsigned int frequency, unsigned int duration) {
    // Example PWM setup for generating tones
    TA0CCR0 = 1000000 / frequency;  // Set PWM period
    TA0CCR1 = TA0CCR0 / 2;         // Set duty cycle
    TA0CTL = TASSEL_2 + MC_1;      // Use SMCLK, up mode
    __delay_cycles(duration * 1000); // Duration in ms
    TA0CTL = MC_0;                 // Stop timer
}
