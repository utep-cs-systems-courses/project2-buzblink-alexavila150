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
  sequence[5] = 3;
  sequence_running = 0;
  song_playing = 0;

  led_index = 0;
  note_index = 0;
  blink_count = 0;
  random_num = 0;
  turn = 0;
  
  
  turn_red_off();
  turn_green_off();
}

void add_to_sequence()
{
  sequence[turn++] = random_num % 2 + 1;
  sequence_running = 1;
}

void end_sequence()
{
  sequence_running = 0;
  led_index = 0;
  blink_count = 0;
  turn_red_off();
  turn_green_off();
}

void play_song()
{
  sequence_running = 0;
  song_playing = 1;
  note_index = 0;
  blink_count = 0;
}










