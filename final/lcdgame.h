#include "lcdgame.h"

/**
 * @brief Initializes the switches on Port 2.
 * 
 * @param mask Mask for the switches to be initialized (e.g., 0x0F for P2.0 to P2.3).
 */
void p2sw_init(unsigned char mask)
{
  P2REN |= mask;  // Enable resistors for switches
  P2OUT |= mask;  // Set pull-up resistors
  P2DIR &= ~mask; // Set switches as inputs
  P2IE |= mask;   // Enable interrupts for the specified switches
  P2IES |= mask;  // Interrupt on high-to-low transition
  P2IFG &= ~mask; // Clear pending interrupt flags
}

/**
 * @brief Reads the state of the switches.
 * 
 * @return unsigned int Returns a 4-bit value where each bit represents the state of a switch (0 for pressed, 1 for not pressed).
 */
unsigned int reader()
{
  return ~P2IN & 0x0F; // Invert and mask the lower 4 bits of
