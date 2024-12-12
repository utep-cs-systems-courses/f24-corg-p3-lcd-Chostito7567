COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Compiler and Assembler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf
	(cd ../timerLib; make)

# Main target to build the program
main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o lcdgame.o input.o lcddraw.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Additional rules for files
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
lcdgame.o: lcdgame.c lcdgame.h
input.o: input.c input.h
lcddraw.o: lcddraw.c lcddraw.h lcdutils.h

# Load the program to the MSP430
load: main.elf
	msp430loader.sh main.elf

# Clean up build files
clean:
	rm -f -r *.o *.elf *shell* *shell*~ *~
	(cd ../timerLib; make clean)
