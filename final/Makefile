COMMON_OBJECTS = stateMachines.o led.o wdInterruptHandler.o switches.o buzzer.o lcdgame.o lcddraw.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

lcdgame.o: lcdgame.c lcdgame.h
	${CC} ${CFLAGS} -c lcdgame.c -o lcdgame.o

lcddraw.o: lcddraw.c lcddraw.h
	${CC} ${CFLAGS} -c lcddraw.c -o lcddraw.o

clean:
	rm -f *.o *.elf

load: main.elf
	mspdebug rf2500 "prog main.elf"
