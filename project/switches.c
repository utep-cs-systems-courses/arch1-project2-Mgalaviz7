#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char SWITCH1 , SWITCH2 , SWITCH3 , SWITCH4 , CURRENT_STATE;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);

  P2IES &= (p2val | ~SWITCHES);

  return p2val;  
}

void
switches_init()      /* setup switches */
{

  P2REN |= SWITCHES;

  P2IE = SWITCHES;

  P2OUT |= SWITCHES;
  
  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();

  led_update();
}
/*
  This method is always actiave waiting to be interputed by the push of a button.
  If any button is pressed it will update the current state that you are currently in.
  By default if no button is pushed the state will be set to 0 a.k.a "ideal" waiting for a button to be pressed.
 */
void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  SWITCH1 = (p2val & SW1) ? 0 : 1;
  SWITCH2 = (p2val & SW2) ? 0 : 1;
  SWITCH3 = (p2val & SW3) ? 0 : 1;
  SWITCH4 = (p2val & SW4) ? 0 : 1;
  
  if(SWITCH1){
    CURRENT_STATE = 1;
    or_sr(0x18);
  }
  if(SWITCH2){
    CURRENT_STATE = 2;
    or_sr(0x18);
  }
  if(SWITCH3){
    CURRENT_STATE = 3;
    or_sr(0x18);
  }
  if(SWITCH4){
    CURRENT_STATE = 4;
    //little_lamb();
    or_sr(0x18);
  }
  else{
    CURRENT_STATE = 0;
    or_sr(0x18);
  }
  led_update();
}
