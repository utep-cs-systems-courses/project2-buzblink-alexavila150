#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

char duration[51];
int notes[51];  

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  rand_num = (rand_num + 1) % 2;
  static int blink_count = 0;
  static int index = 0;
  static char state = 0;
  
  if(sequence_running){
    
    if(++blink_count == 1){
      
      if(index < 6){
	switch(sequence[index++]){
	case 0:
	  sequence_running = 0;
	  index = 0;
	  blink_count = 0;
	  break;
	case 1:
	  turn_red_on();
	  break;
	case 2:
	  turn_green_on();
	  break;
	case 3:
	  sequence_running = 0;
	  index = 0;
	  blink_count = 0;
	  song_playing = 1;
	}
      }else{
	sequence_running = 0;
	index = 0;
	blink_count = 0;
	turn_red_off();
	turn_green_off();
      }
    }

    if(blink_count == 125){
      turn_red_off();
      turn_green_off();
    }

    if(blink_count == 250){
      blink_count = 0;
    }
  }

  if(song_playing){
    turn_red_on();
    turn_green_on();
    //change note every 200 miliseconds
    if(++blink_count == duration[state] * 50 && state < 51){
      state++;
      buzzer_set_period(notes[state] * 2);
      blink_count = 0;
    }

    //make pause when node is ending
    if(blink_count == duration[state] * 50 - 5){
      buzzer_set_period(0);
    }

    //end song
    if(state == 51){
      buzzer_set_period(0);
    }
  }
}
