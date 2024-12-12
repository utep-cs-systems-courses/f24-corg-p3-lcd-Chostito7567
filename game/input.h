#ifndef INPUT_H
#define INPUT_H

#include "switches.h"
void input_process(); 
void input_init(); // Initialize input handling
int input_process(unsigned int *expected_sequence, int sequence_length); // Process user input

#endif // INPUT_H
