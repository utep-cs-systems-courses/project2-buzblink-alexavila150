#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static int blink_count = 0;
  static int state = 0;
  if(++blink_count == 125){
    switch(state){
    case 0:
      turn_red_on();
      state = 1;
      break;
    case 1:
      turn_green_on();
      state = 2;
      break;
    case 2:
      turn_green_off();
      state = 3;
      break;
    case 3:
      turn_red_off();
      state = 0;
      break;
    }
    blink_count = 0;
  }
}
