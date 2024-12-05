# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS         	= -L../lib -L/opt/ti/msp430_gcc/include/ 

# switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: main.elf

# additional rules for files
main.elf: ${COMMON_OBJECTS} main.o lcdgame.o stateMachines.o \
          led.o wdInterruptHandler.o p2_interrupt_handler.o \
          switches.o buzzer.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

lcdgame.o: lcdgame.c lcdgame.h
	${CC} ${CFLAGS} -c $< -o $@

# Rule to load the compiled program onto the MSP430
load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf
