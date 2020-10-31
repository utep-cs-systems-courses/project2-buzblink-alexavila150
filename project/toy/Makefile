# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf 

#additional rules for files
main.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o p2_interrupt_handler.o buzzer.o stateMachines.o wdInterruptHandler.c led.o switches.o main.o song.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

led.o: led.c led.h

stateMachines.o: stateMachines.h led.h

wdInterruptHandler.o: stateMachines.h


clean:
	rm -f *.o *.elf *# ~* *~

