#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"



int
main(void)
{
  configureClocks();

  switches_init();

  buzzer_init();

  led_init();

  enableWDTInterrupts();

  or_sr(0x18);
}
  
