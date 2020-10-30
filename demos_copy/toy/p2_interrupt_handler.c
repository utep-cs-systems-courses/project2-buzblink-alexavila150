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
    add_to_player_sequence(2);
    if(!compare_list()){
      state_init();     //if the sequence is not true then restart the sequence
      return; 
    }

    if(led_index == turn){
      led_index = 0;
      add_to_sequence();
    }
  }

  //SW3 is pressed
  if(P2IFG & S3){
    P2IFG &= ~S3;
    
    add_to_player_sequence(1);
    if(!compare_list()){
      state_init();     //if the sequence is not true then restart the sequence
      return;
    }

    if(led_index == turn){
      led_index = 0;
      add_to_sequence();
    }
    
  }

  //SW4 is pressed
  if(P2IFG & S4){
    P2IFG &= ~S4;
    state_init();
  }
}
