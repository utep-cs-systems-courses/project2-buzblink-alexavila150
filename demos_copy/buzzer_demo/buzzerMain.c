#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
 
    buzzer_init();
    buzzer_set_period(0);	/* start buzzing!!! */

    enableWDTInterrupts();
    or_sr(0x18);          // CPU off, GIE on
}
