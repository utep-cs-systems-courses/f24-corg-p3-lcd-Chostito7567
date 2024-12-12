COMMON_OBJECTS  = main.o stateMachines.o led.o wdInterruptHandler.o \
                  p2_interrupt_handler.o switches.o buzzer.o lcdgame.o input.o

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

# Compiler and Assembler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# Target
all: main.elf

main.elf: ${COMMON_OBJECTS} ../timerLib/libTimer.a ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o ../lcdLib/font-5x7.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

# Clean rule
clean:
	rm -f *.o *.elf *~ *shell* ../lcdLib/*.o ../timerLib/*.o
	(cd ../timerLib; make clean)

# Individual object file dependencies
main.o: main.c
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
lcdgame.o: lcdgame.c lcdgame.h
input.o: input.c input.h

# Include timerLib build rules
../timerLib/libTimer.a:
	(cd ../timerLib; make)

# Include lcdLib object files
../lcdLib/lcddraw.o: ../lcdLib/lcddraw.c ../lcdLib/lcdutils.h ../lcdLib/font-5x7.h
	${CC} ${CFLAGS} -c -o ../lcdLib/lcddraw.o ../lcdLib/lcddraw.c

../lcdLib/lcdutils.o: ../lcdLib/lcdutils.c ../lcdLib/lcdutils.h
	${CC} ${CFLAGS} -c -o ../lcdLib/lcdutils.o ../lcdLib/lcdutils.c

../lcdLib/font-5x7.o: ../lcdLib/font-5x7.c ../lcdLib/font-5x7.h
	${CC} ${CFLAGS} -c -o ../lcdLib/font-5x7.o ../lcdLib/font-5x7.c
