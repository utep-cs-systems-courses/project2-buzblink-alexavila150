#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

//turns red on with unique sound
void turn_red_on()
{
  P1OUT |= LED_RED;
  red_on = 1;
  buzzer_set_period(880);
}

//turns led and sound off
void turn_red_off()
{
  P1OUT &= ~LED_RED;
  red_on = 0;
  buzzer_set_period(0);
}

//turns green and unique sound on
void turn_green_on()
{
  P1OUT |= LED_GREEN;
  green_on = 1;
  buzzer_set_period(784);
}

//turns led and sound off
void turn_green_off()
{
  P1OUT &= ~LED_GREEN;
  green_on = 0;
  buzzer_set_period(0);
}

//call function multiple times to produce a dim red light
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

//call function multiple times to produce a semi dim light
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

//call function multiple times to produce a bright light
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
