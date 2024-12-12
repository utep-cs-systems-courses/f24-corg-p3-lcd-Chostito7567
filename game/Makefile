COMMON_OBJECTS  = stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o lcdgame.o input.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Compiler and Assembler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# Main build target
all: main.elf

main.elf: ${COMMON_OBJECTS} ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Include object files for all components
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
lcdgame.o: lcdgame.c lcdgame.h
input.o: input.c input.h

# Timer library
../timerLib/libTimer.a:
	(cd ../timerLib; make)

# Load program to hardware
load: main.elf
	msp430loader.sh $^

# Clean project
clean:
	rm -f *.o *.elf
	(cd ../timerLib; make clean)
