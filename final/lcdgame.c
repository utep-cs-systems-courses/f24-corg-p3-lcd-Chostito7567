#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "lcdgame.h"

// Function to initialize the switches
void p2sw_init(u_char mask)
{
  P2REN |= mask;  // Enable resistors for switches
  P2OUT |= mask;  // Pull-ups for switches
  P2DIR &= ~mask; // Set switches as inputs
  P2IE |= mask;   // Enable interrupts for switches
  P2IES |= mask;  // Trigger on high-to-low transition
  P2IFG &= ~mask; // Clear interrupt flags
}

// Function to read the state of the switches
u_int reader()
{
  return ~P2IN & 0x0F; // Read the lower 4 bits of P2IN and invert
}

// Interrupt Service Routine for Port 2
void __interrupt_vec(PORT2_VECTOR) Port_2(void)
{
  if (P2IFG & 0x0F) {  // Check if switches triggered the interrupt
    P2IFG &= ~0x0F;    // Clear the interrupt flags
    __bic_SR_register_on_exit(LPM4_bits); // Exit low-power mode
  }
}

/** Initializes everything, clears the screen, and updates on button press */
void lcdscreen()
{
  configureClocks();
  lcd_init();
  p2sw_init(0x0F);   // Initialize the first 4 switches (P2.0 - P2.3)
  or_sr(0x8);        // Enable interrupts (GIE)
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  drawString5x7(10, 10, "switches:", COLOR_GREEN, COLOR_BLUE);

  while (1) {
    __bis_SR_register(LPM4_bits + GIE); // Enter low-power mode, enable interrupts

    u_int switches = reader(), i;
    char str[5];
    for (i = 0; i < 4; i++) {
      str[i] = (switches & (1 << i)) ? '0' + i : '-';
    }
    str[4] = 0;

    clearScreen(COLOR_BLUE); // Clear the screen before updating
    drawString5x7(10, 10, "switches:", COLOR_GREEN, COLOR_BLUE);
    drawString5x7(20, 20, str, COLOR_GREEN, COLOR_BLUE);
  }
}
