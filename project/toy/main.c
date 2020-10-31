#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"

void main(void) 
{  
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();

  state_init();
  
  or_sr(0x18);  // CPU off, GIE on
} 
