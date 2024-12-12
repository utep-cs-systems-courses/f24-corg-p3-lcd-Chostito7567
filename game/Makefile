COMMON_OBJECTS  = main.o stateMachines.o led.o switches.o buzzer.o input.o lcdgame.o lcddraw.o lcdutils.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include -L../lib

# Compiler and assembler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# Target to build the main program
all: main.elf

main.elf: ${COMMON_OBJECTS} ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Compile individual files
main.o: main.c
	${CC} ${CFLAGS} -c -o $@ $<

stateMachines.o: stateMachines.c stateMachines.h
	${CC} ${CFLAGS} -c -o $@ $<

led.o: led.c led.h
	${CC} ${CFLAGS} -c -o $@ $<

switches.o: switches.c switches.h
	${CC} ${CFLAGS} -c -o $@ $<

buzzer.o: buzzer.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

input.o: input.c input.h switches.h
	${CC} ${CFLAGS} -c -o $@ $<

lcdgame.o: lcdgame.c lcdgame.h lcddraw.h
	${CC} ${CFLAGS} -c -o $@ $<

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h font-5x7.h
	${CC} ${CFLAGS} -c -o $@ $<

lcdutils.o: lcdutils.c lcdutils.h
	${CC} ${CFLAGS} -c -o $@ $<

# Load the program to the device
load: main.elf
	msp430loader.sh $^

# Clean the build directory
clean:
	rm -f *.o *.elf
