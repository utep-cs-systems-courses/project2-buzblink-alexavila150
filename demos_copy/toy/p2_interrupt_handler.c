#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  //SW1 is pressed
  if(P2IFG & S1){
    P2IFG &= ~S1;
    play_song();
  }

  //SW2 is pressed
  if(P2IFG & S2){
    P2IFG &= ~S2;
    turn_red_on();
  }

  //SW3 is pressed
  if(P2IFG & S3){
    P2IFG &= ~S3;
    turn_green_on();
  }

  //SW4 is pressed
  if(P2IFG & S4){
    P2IFG &= ~S4;
    state_init();
  }
}
