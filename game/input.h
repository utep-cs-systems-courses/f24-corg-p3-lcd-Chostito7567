#ifndef INPUT_H
#define INPUT_H

#include "switches.h"

// Function declaration for input initialization
void input_init(); 

// Function declaration for processing user input
int input_process(unsigned int *expected_sequence, int sequence_length);

#endif // INPUT_H
