#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stateMachines.h"
#include "led.h"

void state_init()
{
  for(int i = 0; i < 5; i++){
    sequence[i] = 0;
  }
  sequence_running = 0;
}

void add_to_sequence()
{
  static char index = 0;
  sequence[index++] = rand_num + 1;
  sequence_running = 1;
}















