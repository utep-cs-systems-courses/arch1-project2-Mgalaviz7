#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT6    //p1.6
#define LED_GREEN BIT0  //p1.0

#define LEDS (BIT0 | BIT6)

void led_init();

void led_update();

void green_led_on();

void red_led_on();

extern unsigned char red, green;

extern unsigned char green_on, red_on;

extern unsigned char led_changed;



#endif //include
