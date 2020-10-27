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
  note_index = 0;
  blink_count = 0;
}

void add_to_sequence()
{
  static char index = 0;
  sequence[index++] = blink_count % 2 + 1;
  sequence_running = 1;
}

void play_song()
{
  sequence_running = 0;
  song_playing = 1;
  note_index = 0;
}










