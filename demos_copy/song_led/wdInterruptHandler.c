#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static int blink_count = 1;
  static char state = 0;

  switch(state){
  case 0: // First state to turn on the red light at first
    red_turn_on();
  case 1: // This state increments the frequency and then goes to state 2
    if(++blink_count % 25 == 0){
      incrementFrequency();
    }

    if(hz == 5000){
      blink_count = 0;
      state = 2;
      red_off();
      green_turn_on();
    }
    break;
  case 2: //This state decreases the frequency and then goes to state 1
    if(++blink_count % 25 == 0){
      decrementFrequency();
    }

    if(hz == 500){
      blink_count = 0;
      state = 1;
      green_off();
      red_turn_on();
    }
    break;
  }
}


