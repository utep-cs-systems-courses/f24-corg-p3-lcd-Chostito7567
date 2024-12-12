#include <msp430.h>
#include <stdlib.h>

// Define button inputs and states
#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3

unsigned char safe_wires[4];  // Array to track safe wires
unsigned char used_wires[4]; // Array to track used wires (1 = disabled)

// Function prototypes
void setup_gpio();
void setup_game();
void draw_screen();
void remove_wire(unsigned char wire);
void red_boom();
void display_message(const char *message);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer
    setup_gpio();
    setup_game();

    draw_screen();

    while (1) {
        if (!(P1IN & S1) && !used_wires[0]) {  // S1 pressed
            if (safe_wires[0]) remove_wire(0);
            else red_boom();
        } else if (!(P1IN & S2) && !used_wires[1]) {  // S2 pressed
            if (safe_wires[1]) remove_wire(1);
            else red_boom();
        } else if (!(P1IN & S3) && !used_wires[2]) {  // S3 pressed
            if (safe_wires[2]) remove_wire(2);
            else red_boom();
        } else if (!(P1IN & S4) && !used_wires[3]) {  // S4 pressed
            if (safe_wires[3]) remove_wire(3);
            else red_boom();
        }
    }
}

void setup_gpio() {
    P1DIR &= ~(S1 | S2 | S3 | S4); // Set S1–S4 as input
    P1REN |= S1 | S2 | S3 | S4;    // Enable pull-up/down resistors
    P1OUT |= S1 | S2 | S3 | S4;    // Set resistors to pull-up
}

void setup_game() {
    // Initialize all wires as unused
    for (unsigned char i = 0; i < 4; i++) {
        used_wires[i] = 0;
    }

    // Randomly select one safe wire
    unsigned char safe_index = rand() % 4;
    for (unsigned char i = 0; i < 4; i++) {
        safe_wires[i] = (i == safe_index) ? 1 : 0;
    }
}

void draw_screen() {
    // Placeholder for drawing colored rectangles on the LCD
    // Example: draw a rectangle for each wire
    // draw_rectangle(x, y, width, height, color);
}

void remove_wire(unsigned char wire) {
    used_wires[wire] = 1;  // Mark the wire as used
    // Clear the rectangle representing this wire
    // clear_rectangle(wire_position_x, wire_position_y, wire_width, wire_height);
    display_message("Wire Removed!");
}

void red_boom() {
    // Display red boom screen
    // fill_screen(RED);
    display_message("BOOM!");
    while (1);  // Stop game after explosion
}

void display_message(const char *message) {
    // Placeholder for displaying a message on the LCD
    // lcd_print(message);
    __no_operation();
}
