#include <msp430.h>
#include "led.h"

unsigned char red_on , green_on =0;

static char redVal[] = {0, LED_RED} , greenVal[] = {0, LED_GREEN};


void
led_init()
{
  P1DIR |= LEDS;
  led_update();
}

void
led_update()
{
  char ledFlags = redVal[red_on] | greenVal[green_on];

  P1OUT &=(0xff^LEDS) | ledFlags;

  P1OUT |= ledFlags;
}

void
green_led_on()
{
  green_on = 1;
  led_update();  
}

void
green_led_off()
{
  green_on = 0;
  led_update();  
}

void
red_led_on()
{
  red_on = 1;
  led_update();
}

void
red_led_off()
{
  red_on = 0;
  led_update();
}

void
both_leds_on()
{
  green_on = 1;
  red_on = 1;
  led_update();
}

void
both_leds_off()
{
  green_on = 0;
  red_on = 0;
  led_update();
}

