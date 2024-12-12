COMMON_OBJECTS  = stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o input.o lcdgame.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf
	(cd ../timerLib; make)
	(cd ../lcdLib; make)

# Additional rules for files
main.elf: ${COMMON_OBJECTS} ../timerLib/libTimer.a ../lcdLib/lcdutils.o ../lcdLib/lcddraw.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f -r *.o *.elf *~ *#
	(cd ../timerLib; make clean)
	(cd ../lcdLib; make clean)

# Object dependencies
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
input.o: input.c input.h
lcdgame.o: lcdgame.c lcdgame.h
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
