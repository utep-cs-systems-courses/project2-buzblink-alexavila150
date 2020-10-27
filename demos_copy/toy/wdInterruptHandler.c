#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  
  if(sequence_running){
    
    if(++blink_count == 1){
      
      if(led_index < 6){
	switch(sequence[led_index++]){
	case 0:
	  sequence_running = 0;
	  led_index = 0;
	  blink_count = 0;
	  break;
	case 1:
	  turn_red_on();
	  break;
	case 2:
	  turn_green_on();
	  break;
	case 3:
	  play_song();
	  break;
	}
      }else{
	sequence_running = 0;
	led_index = 0;
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
    //change note every 200 miliseconds
    if(++blink_count == duration[note_index] * 50 && note_index < 42){
      note_index++;
      buzzer_set_period(notes[note_index] * 2);
      blink_count = 0;
    }

    //make pause when node is ending
    if(blink_count == duration[note_index] * 50 - 5){
      buzzer_set_period(0);
    }

    //end song
    if(note_index == 42){
      buzzer_set_period(0);
    }
  }
}
