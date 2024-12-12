COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Compiler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# Targets
all: main.elf

# Linking
main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o switches.o buzzer.o lcdgame.o lcddraw.o lcdutils.o input.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Compiling Object Files
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
lcdgame.o: lcdgame.c lcdgame.h
lcddraw.o: lcddraw.c lcddraw.h
lcdutils.o: lcdutils.c lcdutils.h
input.o: input.c input.h

# Load program
load: main.elf
	msp430loader.sh main.elf

# Clean up
clean:
	rm -f *.o *.elf
