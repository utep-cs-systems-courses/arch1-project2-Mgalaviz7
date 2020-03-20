#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define _A 1760
#define _G 3135
#define _F 2793
#define _C 2093

#define _D 1174
#define _E 1318

static int *little_lamb_song;

#define SONG_LEN 27

void
buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;

  P2DIR = BIT6;
}

void
buzzer_set_period(short cycles)
{
  TA0CCR0 = cycles;
  TA0CCR1 = cycles >> 5;
}

void
little_lamb()
{
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(_F); //_F
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(0);
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(0); 
  buzzer_set_period(_A); //_A
  note_duration(3);
  
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(0);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(0);
  buzzer_set_period(_G); //_G
  note_duration(3);
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(_C); //_C
  note_duration(1);
  buzzer_set_period(0);
  buzzer_set_period(_C); //_C
  note_duration(3);

  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(_F); //_F
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(0);
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(0); 
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(0);
 
  buzzer_set_period(_F); //_A
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(0);  
  buzzer_set_period(_G);  //_G
  note_duration(1);
  buzzer_set_period(0);
 
  buzzer_set_period(_A); //_A
  note_duration(1);
  buzzer_set_period(_G); //_G
  note_duration(1);
  buzzer_set_period(_F); //_F
  note_duration(4);
  buzzer_set_period(0);
  note_duration(2);
}

void
note_duration(int rest){

  switch (rest)
    {
      //quater note~
      case 1:
	__delay_cycles(16000000/2);
      break;

      //half note~
      case 2:
	__delay_cycles(16000000/8);
      break;

      //whole note~
      case 3:
	__delay_cycles(16000000/1);
      break;

      //last Note
      case 4:
	__delay_cycles(17000000);
      break;
  }
}


void
little_lamb_notes(){
  /*
  little_lamb_song = (int *)malloc(sizeof(int) * (SONG_LEN + 1));

  little_lamb_song[0] = _A;
  little_lamb_song[1] = _A;
  little_lamb_song[2] = _A;
  little_lamb_song[3] = _A;
  
  little_lamb_song[4] = _A;
  little_lamb_song[5] = _A;
  little_lamb_song[6] = _A;
  little_lamb_song[7] = _A;
 
  little_lamb_song[8] = _A;
  little_lamb_song[9] = _A;
  little_lamb_song[10] = _A;
  little_lamb_song[11] = _A;

  little_lamb_song[12] = _A;
  little_lamb_song[13] = _A;
  little_lamb_song[14] = _A;
  little_lamb_song[15] = _A;

  little_lamb_song[16] = _A;
  little_lamb_song[17] = _A;
  little_lamb_song[18] = _A;
  little_lamb_song[19] = _A;

  little_lamb_song[20] = _A;
  little_lamb_song[21] = _A;
  little_lamb_song[22] = _A;
  little_lamb_song[23] = _A;

  little_lamb_song[24] = _A;
  little_lamb_song[25] = _A;
  little_lamb_song[26] = _A;

  little_lamb_song[27] = "/0";
  
  }
  */
}