#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stateMachines.h"
#include "led.h"


void state_init()
{
  int notes[51] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    659, 493, 523, 587, 523, 493, 440, 440, 523, 659,
    587, 523, 493, 523, 587, 659, 523, 440, 440, 440,
    493, 523, 587, 698, 880, 783, 698, 659, 523, 659,
    587, 523, 493, 493, 523, 587, 659, 523, 440, 440,
    0
  };

  char duration[51] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 2, 1, 1, 2, 1, 1, 2,
    1, 1, 3, 1, 2, 2, 2, 2, 1, 1,
    1, 1, 3, 1, 2, 1, 1, 3, 1, 2,
    1, 1, 2, 1, 1, 2, 2, 2, 2, 2,
    1,
  };

  for(int i = 0; i < 5; i++){
    sequence[i] = 0;
  }
  sequence[5] = 3;
  sequence_running = 0;
}

void add_to_sequence()
{
  static char index = 0;
  sequence[index++] = rand_num + 1;
  sequence_running = 1;
}










