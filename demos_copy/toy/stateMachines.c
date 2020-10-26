#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include "stateMachines.h"
#include "led.h"

void state_init()
{
  for(int i = 0; i < 5; i++){
    sequence[i] = 0;
  }
  sequence_running = 0;
  add_to_sequence();
}

void add_to_sequence()
{
  static char index = 0;

  //get random number either 1 or 2
  char random_num = rand() % 2 + 1;
  sequence[index++] = random_num;
  sequence_running = 1;
}















