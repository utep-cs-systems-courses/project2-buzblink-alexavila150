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

  for(int i = 0; i < 5; i++){
    player_sequence[i] = 0;
  }
  
  sequence_running = 0;
  song_playing = 0;

  led_index = 0;
  note_index = 0;
  blink_count = 0;
  turn = 0;
  random_num = 0;
  
  turn_red_off();
  turn_green_off();
}

void reset_sequence()
{
  char temp_random = random_num;  //hold random number when reseting
  state_init();
  random_num = temp_random;
  add_to_sequence();
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

void add_to_player_sequence(char led)
{
  player_sequence[led_index++] = led;
}

char compare_list()
{
  int i;
  for(i = 0; i < 6; i++){
    if(sequence[i] != player_sequence[i] && player_sequence[i] != 0){
      return 0;
    }
  }
  return 1;
}








