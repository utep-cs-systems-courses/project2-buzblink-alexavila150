#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  //SW1 plays the song and it also has the red led increasing brightness every 15 seconds
  if(P2IFG & S1){  
    P2IFG &= ~S1;
    play_song();
  }

  //SW2 adds green to the player sequence
  if(P2IFG & S2){
    P2IFG &= ~S2;
    add_to_player_sequence(2);
    
    //if the sequence is not true then restart the sequence
    if(!compare_list()){
      reset_sequence();    
      return; 
    }

    // if sequence was true then play the next sequence of lights
    if(led_index == turn){
      led_index = 0;
      add_to_sequence();
    }
  }

  //SW3 adds red to the player sequence
  if(P2IFG & S3){
    P2IFG &= ~S3;
    add_to_player_sequence(1);

    //if the sequence is not true then restart the sequence
    if(!compare_list()){
      reset_sequence();     
      return;
    }

    //if sequence is correct then play the next sequence of leds
    if(led_index == turn){
      led_index = 0;
      add_to_sequence();
    }
    
  }

  //SW4 restarts game into a new one
  if(P2IFG & S4){
    P2IFG &= ~S4;
    reset_sequence();
  }
}
