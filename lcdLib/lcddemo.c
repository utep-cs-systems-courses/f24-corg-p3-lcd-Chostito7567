#include <msp430.h>

// Pin definitions (adjust according to your setup)
#define RS BIT0   // P1.0
#define E  BIT1   // P1.1
#define D4 BIT2   // P1.2
#define D5 BIT3   // P1.3
#define D6 BIT4   // P1.4
#define D7 BIT5   // P1.5

void delay_ms(unsigned int ms) {
    while (ms--) __delay_cycles(1000); // Adjust for your clock speed
}

void lcd_pulse_enable() {
    P1OUT |= E;
    __delay_cycles(100); // Small delay for enable pulse
    P1OUT &= ~E;
}

void lcd_send_nibble(unsigned char nibble) {
    P1OUT &= ~(D4 | D5 | D6 | D7); // Clear data pins
    P1OUT |= (nibble & 0x0F) << 2; // Set data pins
    lcd_pulse_enable();
}

void lcd_send_byte(unsigned char byte, unsigned char is_data) {
    if (is_data)
        P1OUT |= RS;
    else
        P1OUT &= ~RS;

    lcd_send_nibble(byte >> 4); // Send high nibble
    lcd_send_nibble(byte & 0x0F); // Send low nibble
    delay_ms(2); // Wait for command to execute
}

void lcd_init() {
    P1DIR |= RS | E | D4 | D5 | D6 | D7; // Set pins as outputs
    P1OUT &= ~(RS | E | D4 | D5 | D6 | D7);

    delay_ms(20); // Power-on delay

    lcd_send_nibble(0x03); // Initialize
    delay_ms(5);
    lcd_send_nibble(0x03);
    delay_ms(1);
    lcd_send_nibble(0x03);
    lcd_send_nibble(0x02); // Set to 4-bit mode

    lcd_send_byte(0x28, 0); // Function set: 4-bit, 2 lines, 5x8 dots
    lcd_send_byte(0x0C, 0); // Display on, cursor off
    lcd_send_byte(0x06, 0); // Entry mode set: Increment, no shift
    lcd_send_byte(0x01, 0); // Clear display
    delay_ms(2);
}

void lcd_print(const char *str) {
    while (*str) {
        lcd_send_byte(*str++, 1); // Send characters to LCD
    }
}

int main() {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    lcd_init(); // Initialize LCD
    lcd_print("Hello, MSP430!"); // Display message

    while (1) {
        // Main loop
    }
}
