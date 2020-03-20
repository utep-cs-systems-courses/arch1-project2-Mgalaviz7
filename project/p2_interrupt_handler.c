#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT() {
  static char blink_count =0;
  if(++blink_count == 125){
    state();
    blink_count=0;
  }
}
