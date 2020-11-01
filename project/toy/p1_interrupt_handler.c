
#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES && !sequence_running) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    add_to_sequence();                  // this button will just play the next sequence
  }
}

