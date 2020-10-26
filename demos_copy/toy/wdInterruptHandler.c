#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state = 0;
  if (++blink_count != 250) {
    
    switch(state){
    case 0:
      toggle_red();
      break;
    case 1:
      red_dim();
      break;
    case 2:
      red_bright();
      break;
    }  

    led_changed = 1;
    led_update();
  }else{
    state = (state + 1) % 3; //change state 
    blink_count = 0; // reset blink count
  }
}
