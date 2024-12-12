COMMON_OBJECTS = stateMachines.o led.o wdInterruptHandler.o switches.o buzzer.o lcdgame.o lcdutils.o lcddraw.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf
