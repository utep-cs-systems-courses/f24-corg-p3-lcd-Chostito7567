# Configuration
COMMON_OBJECTS = main.o lcdgame.o input.o stateMachines.o led.o buzzer.o switches.o wdInterruptHandler.o p2_interrupt_handler.o lcddraw.o lcdutils.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I. -L../timerLib
LDFLAGS = -L/opt/ti/msp430_gcc/include -L../timerLib

# Compiler and Assembler
CC = msp430-elf-gcc
AS = msp430-elf-as

# Main Target
all: main.elf

main.elf: ${COMMON_OBJECTS} ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Object File Rules
main.o: main.c
	${CC} ${CFLAGS} -c -o $@ $<

lcdgame.o: lcdgame.c lcdgame.h
	${CC} ${CFLAGS} -c -o $@ $<

input.o: input.c input.h switches.h
	${CC} ${CFLAGS} -c -o $@ $<

stateMachines.o: stateMachines.c stateMachines.h
	${CC} ${CFLAGS} -c -o $@ $<

led.o: led.c led.h
	${CC} ${CFLAGS} -c -o $@ $<

buzzer.o: buzzer.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

switches.o: switches.c switches.h
	${CC} ${CFLAGS} -c -o $@ $<

wdInterruptHandler.o: wdInterruptHandler.c
	${CC} ${CFLAGS} -c -o $@ $<

p2_interrupt_handler.o: p2_interrupt_handler.c
	${CC} ${CFLAGS} -c -o $@ $<

lcddraw.o: lcddraw.c lcddraw.h font-5x7.h lcdutils.h
	${CC} ${CFLAGS} -c -o $@ $<

lcdutils.o: lcdutils.c lcdutils.h
	${CC} ${CFLAGS} -c -o $@ $<

# Cleaning Rule
clean:
	rm -f *.o *.elf
	rm -f *~ *.bak

# Loading Rule
load: main.elf
	msp430loader.sh $^

# Timer Library
../timerLib/libTimer.a:
	(cd ../timerLib; make)
