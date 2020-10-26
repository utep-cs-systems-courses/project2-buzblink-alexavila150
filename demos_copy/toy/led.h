#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT6               // P1.0
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

char red_on;                       //tells if red is on
char green_on;                     //tells if green is on

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */
void turn_red_on();
void turn_red_off();
void turn_green_on();
void turn_green_off();

// these are boolean flags
extern unsigned char leds_changed, green_led_state, red_led_state;

#endif
