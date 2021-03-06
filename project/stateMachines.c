#include <msp430.h>
#include <stdlib.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_transition_assembly.h"

int dim_flag = 0;
char speed = 125;

/*
  This method is always toggled and is used to keep the current state
  of the state machine. Each state changes due to the time a button is
  pushed and remains in that state till another button is pushed.
*/
void
states_transition()
{
  states();    
  /*
  char state = CURRENT_STATE;

  switch (state)
    {
      /* STATE_0
	 While in STATE_0 it will turn on the green led. 
      
    case 0:
      green_led_on();   
      state = 0;
      break;      
      /* STATE_1
	 While in STATE_1 it will call the method count_to_3 
	 which will blink the leds in a numerical fashion.
      
    case 1:
      dim_flag = 0;
      count_to_3();
      state = 1;
      break;
      
      /* STATE_2
	 While in STATE_2 it will set the dim led flag to true 
	 and will dim the lights as it counts to 3.
      
    case 2:
      dim_flag = 1;
      count_to_3();
      state = 2;
      break;
      
      /* STATE_3
	 While in STATE_3 it will increase the speed at which 
	 leds a blinked an restarts the speed and processes once it reaches 
	 the fastes speed possible.
         
    case 3:
      speed -= 1;
      if (speed < 1)
	{
	  speed = 125;
	}
      count_to_3();
      state = 3;
      break;
      
      /* STATE_4
	 While in STATE_4 it will call the method little lamb 
	 which will play the melody.
      
    case 4:
      little_lamb();
      state = 4;
      break;
  }*/
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
  
  switch (state)
    {
      /* Number 0: turn off both leds for binary value of 0 */
    case 0:
      both_leds_off();
      state = 1;
      break;
      
      /* Number 1: turn on red led for binary value of 1 */
    case 1:
      if (dim_flag)
	{
	  for (int i =0; i<100; i++)
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
      
      /* Number 2: turn on green led for binary value of 2 */
    case 2:
      if (dim_flag)
	{
	  for (int i =0; i<100; i++)
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
      
      /* Number 3: turn on both leds for binary value of 3 */
    case 3:
      if (dim_flag)
	{
	  for (int i =0; i<100; i++)
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
