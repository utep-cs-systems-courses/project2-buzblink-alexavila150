#include <msp430.h>
#include "buzzer.h"

static int notes[51] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  659, 493, 523, 587, 523, 493, 440, 440, 523, 659,
  587, 523, 493, 523, 587, 659, 523, 440, 440, 440,
  493, 523, 587, 698, 880, 783, 698, 659, 523, 659,
  587, 523, 493, 493, 523, 587, 659, 523, 440, 440,
  0
};

static char duration[51] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 1, 1, 2, 1, 1, 2, 1, 1, 2,
  1, 1, 3, 1, 2, 2, 2, 2, 1, 1,
  1, 1, 3, 1, 2, 1, 1, 3, 1, 2,
  1, 1, 2, 1, 1, 2, 2, 2, 2, 2,
  1,
};

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state = 0;

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
