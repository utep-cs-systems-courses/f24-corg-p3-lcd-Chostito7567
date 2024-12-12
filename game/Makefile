COMMON_OBJECTS  = stateMachines.o led.o switches.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Compiler settings
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# All target
all: main.elf

# Main ELF target
main.elf: main.o lcdgame.o input.o ${COMMON_OBJECTS} ../timerLib/libTimer.a lcddraw.o lcdutils.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Object file dependencies
main.o: main.c
lcdgame.o: lcdgame.c lcdgame.h lcdutils.h lcddraw.h font-5x7.h
input.o: input.c input.h switches.h lcdutils.h
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
p2_interrupt_handler.o: p2_interrupt_handler.c
wdInterruptHandler.o: wdInterruptHandler.c
lcddraw.o: lcddraw.c lcddraw.h font-5x7.h
lcdutils.o: lcdutils.c lcdutils.h

# Load target
load: main.elf
	msp430loader.sh main.elf

# Clean target
clean:
	rm -f *.o *.elf
	rm -f ../timerLib/*.o
