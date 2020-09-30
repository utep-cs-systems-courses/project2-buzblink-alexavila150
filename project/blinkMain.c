//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#inclede "led.h"

int main(void){
  configureClocks();      // setup master oscillator, CPU & peripherical clocks
  led_init();             
  enableWDTInterrupts;    // enable periodic interrupt

  or_sr(0x18);
}









