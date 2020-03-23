#include <msp430.h>
#include <stdlib.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static int blink_flag;
char speed = 125;
/*
  This method is always toggled and is used to keep the current state
  of the state machine. Each state changes due to the time a button is
  pushed and remains in that state till another button is pushed.
  Read the README to get a better in depth understanging or each state
  and button fucnctionality.
 */
void
states()
{
  char state = CURRENT_STATE ;
  
  
  switch (state) {
  case 0:
    /* Is currently shown that it is at state 0 and ready to go*/
    green_led_on();   
    state = 0;
    break;

  case 1:
    blink_flag = 0;
    //state_1(CURRENT_STATE);
    count_to_3();
    state = 1;
    break;

  case 2:
    blink_flag = 1;
    count_to_3();
    state = 2;
    break;

  case 3:
    speed -= 1;
    if(speed < 1){
      speed = 125;
    }
    count_to_3();
    state = 3;
    break;

  case 4:
    little_lamb();
    state = 4;
    break;
  }
}

/*
  This method is always toggled either when button1 or button2 is pressed. 
  If button 1 is pressed it counts from 0 to the value 3 in binary rersination.
  By calling the methods in led.c
  If button 2 is pressed it trigres the dim flag which essentialy dims the counting to
  3.
 */
void
count_to_3()
{  
  static char state = 0;
  
  switch (state) {
  case 0:
    both_leds_off();
    state = 1;
    break;

  case 1:
    if (blink_flag == 1)
      {
	for(int i =0; i<100; i++)
	  {
	    red_led_on();
	    red_led_off();
	  }
      }
    else
      {
	red_led_on();
      }
    state = 2;
    break;
    
  case 2:
     if(blink_flag == 1)
      {
	for(int i =0; i<100; i++)
	  {
	    red_led_off();
	    green_led_on();
	    green_led_off();
	  }
      }
     else
      {
	red_led_off();
	green_led_on();
      }
     state = 3;
     break;

  case 3:
    if(blink_flag == 1)
      {
	for(int i =0; i<100; i++)
	  {
	    both_leds_on();
	    both_leds_off();
	  }
      }
    else
      {
	both_leds_on();
      }
    state = 0;
    break;
  }
  led_update();
}
