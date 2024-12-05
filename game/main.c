#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"

void main()
{
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize 
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs

    // LCD Initialization
    lcd_init();                 // Initialize the LCD
    clearScreen(COLOR_BLUE);    // Clear the screen with a blue background

    // Draw Rectangle
    u_char topLeftX = screenWidth / 4;          // Left edge
    u_char topLeftY = screenHeight / 4;         // Top edge
    u_char rectWidth = screenWidth / 2;         // Rectangle width
    u_char rectHeight = screenHeight / 4;       // Rectangle height
    drawRectOutline(topLeftX, topLeftY, rectWidth, rectHeight, COLOR_GREEN);

    // Write Text Inside
    u_char textX = topLeftX + 10;               // Offset from left edge
    u_char textY = topLeftY + rectHeight / 2;   // Center text vertically
    drawString5x7(textX, textY, "1,2,3,4", COLOR_WHITE, COLOR_BLUE);

    // Watchdog
    enableWDTInterrupts();      // Enable Watchdog Timer

    // Power off CPU
    or_sr(0x18);
}
