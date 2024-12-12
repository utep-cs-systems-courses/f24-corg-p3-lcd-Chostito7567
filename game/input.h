#ifndef INPUT_INCLUDED
#define INPUT_INCLUDED

#define SW1 BIT0  // Button 1
#define SW2 BIT1  // Button 2
#define SW3 BIT2  // Button 3
#define SW4 BIT3  // Button 4

void input_init();  // Initialize the input system
int input_process(unsigned int* expected_sequence, int sequence_length);  // Process user input

#endif // INPUT_INCLUDED
