COMMON_OBJECTS  = stateMachines.o led.o switches.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -I../lcdLib
LDFLAGS         = -L/opt/ti/msp430_gcc/include -L../lcdLib

# Compiler settings
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# All target
all: main.elf

# Main ELF target
main.elf: main.o lcdgame.o input.o ${COMMON_OBJECTS} ../timerLib/libTimer.a ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o ../lcdLib/font-5x7.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Object file dependencies
main.o: main.c
lcdgame.o: lcdgame.c lcdgame.h ../lcdLib/lcdutils.h ../lcdLib/lcddraw.h ../lcdLib/font-5x7.h
input.o: input.c input.h switches.h ../lcdLib/lcdutils.h
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
p2_interrupt_handler.o: p2_interrupt_handler.c
wdInterruptHandler.o: wdInterruptHandler.c
../lcdLib/lcddraw.o: ../lcdLib/lcddraw.c ../lcdLib/lcddraw.h ../lcdLib/font-5x7.h
../lcdLib/lcdutils.o: ../lcdLib/lcdutils.c ../lcdLib/lcdutils.h

# Load target
load: main.elf
	msp430loader.sh main.elf

# Clean target
clean:
	rm -f *.o *.elf
	rm -f ../lcdLib/*.o
	rm -f ../timerLib/*.o
