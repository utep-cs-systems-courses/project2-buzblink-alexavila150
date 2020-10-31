#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

//void led_update(){
//if (switch_state_changed) {
//  char ledFlags = 0; /* by default, no LEDs on */
//
//  ledFlags |= switch_state_down ? LED_GREEN : 0;
//  ledFlags |= switch_state_down ? 0 : LED_RED;
//
//  P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
//  P1OUT |= ledFlags;         // set bits for on leds
//}
//switch_state_changed = 0;
//}

void turn_red_on()
{
  P1OUT |= LED_RED;
  red_on = 1;
  buzzer_set_period(880);
}

void turn_red_off()
{
  P1OUT &= ~LED_RED;
  red_on = 0;
  buzzer_set_period(0);
}

void turn_green_on()
{
  P1OUT |= LED_GREEN;
  green_on = 1;
  buzzer_set_period(784);
}

void turn_green_off()
{
  P1OUT &= ~LED_GREEN;
  green_on = 0;
  buzzer_set_period(0);
}

void turn_red_dim()
{
  static char state = 0;
  switch(state){
  case 0:
    P1OUT &= ~LED_RED;
    red_on = 0;
    break;
  case 3:
    P1OUT |= LED_RED;
    red_on = 1;
    break;
  }

  state = (state + 1) % 4;
}

void turn_red_middle()
{
  static char state = 0;
  switch(state){
  case 0:
    P1OUT |= LED_RED;
    red_on = 1;
    break;
  case 2:
    P1OUT &= ~LED_RED;
    red_on = 0;
    break;
  }

  state = (state + 1) % 4;
}

void turn_red_bright()
{
  static char state = 0;
  switch(state){
  case 0:
    P1OUT |= LED_RED;
    red_on = 1;
    break;
  case 3:
    P1OUT &= ~LED_RED;
    red_on = 0;
    break;
  }

  state = (state + 1) % 4;
}
