#ifndef switches_include
#define switches_include

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switches_init();

void switch_interrupt_handler();

//void green_led_on();
extern char SWITCH1 , SWITCH_STATE;

#endif //included
