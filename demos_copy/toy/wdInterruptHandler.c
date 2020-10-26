#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  rand_num = (rand_num + 1) % 2;
  static int blink_count = 0;
  static int index = 0;
  
  if(sequence_running){
    
    if(++blink_count == 1){
      
      if(index < 5){
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
}
