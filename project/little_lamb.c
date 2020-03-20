#include "msp430.h"
#include <stdlib.h>

#define _A 36364
#define _G 40816
#define _F 45815
#define _C 61156

#define meldoy_len 27
static *little_lamb

int main() {
  WDTCTL = WDTPW | WDTHOLD;//stop watchdog timer
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;

  P2SEL &= ~(BIT6 | BIT7);
  P2OUT &= ~BIT6;
  P2DIR = BIT6;

  P2SEL |= BIT6;
  TA0CCR0 =0;
  TA0CCR1 =0;
  TA0CTL = TASSEL_2 + MC_1 + ID_2;
  TA0CCR1 = OUTMODE_3;
  
  little_lamb = malloc(sizeof(mellody_len)); 
  little_lamb_melody();

  int i=0;
  while(i<=mellody_len){
    TA0CCR0 = (*little_lamb_mellody+i);
    TA0CCR1 = (*little_lamb_mellody+i);
    i+=1;
    TA0CCR0 = 0;
    TA0CCR1 = 0;
  }
}

void little_lamb_melody () {

  little_lamb[] = 
  





}
