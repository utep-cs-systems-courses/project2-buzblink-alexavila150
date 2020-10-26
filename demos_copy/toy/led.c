#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  //led_update();
  turn_red_on();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

void turn_red_on()
{
  P1OUT |= LED_RED;
}

void turn_red_off()
{
  P1OUT &= ~LED_RED;
}

void turn_green_on()
{
  P1OUT |= LED_GREEN;
}

void turn_green_off()
{
  P1OUT &= ~LED_GREEN;
}
