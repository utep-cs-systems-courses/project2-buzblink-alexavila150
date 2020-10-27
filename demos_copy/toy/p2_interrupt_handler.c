#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & S1){
    P2IFG &= ~S1;
    play_song();
    turn_red_on();
  }
}
