#include "libTimer.h"
#include <msp430.h>

void configureClocks() {
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;

    BCSCTL2 &= ~(DIVS_3); // SMCLK = DCO / 1
}
