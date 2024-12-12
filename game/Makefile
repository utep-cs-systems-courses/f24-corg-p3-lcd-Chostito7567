COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o switches.o buzzer.o input.o lcdgame.o lcddraw.o lcdutils.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf *~
