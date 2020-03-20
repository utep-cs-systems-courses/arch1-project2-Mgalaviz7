# makefile
COMMON_OBJECTS =
CPU 	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../demos/h -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

#switch the complier (for the internal make rules)
CC	       = msp430-elf-gcc
AS	       = msp430-eld-as

all: lab2.elf

#additional rules for files
lab2.elf: ${COMMON_OBJECTS}  lab2.o stateMachines.o switches.o buzzer.o led.o p2_interrupt_handler.o  ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: lab2.elf
	msp430loader.sh lab2.elf

clean:
	rm -f *.o *.elf *~
