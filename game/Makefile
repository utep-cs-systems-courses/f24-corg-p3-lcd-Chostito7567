COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

# Compiler
CC = msp430-elf-gcc

all: main.elf

main.elf: main.c lcdgame.o input.o switches.o ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

lcdgame.o: lcdgame.c lcdgame.h
	${CC} ${CFLAGS} -c $< -o $@

input.o: input.c input.h
	${CC} ${CFLAGS} -c $< -o $@

switches.o: switches.c switches.h
	${CC} ${CFLAGS} -c $< -o $@

../lcdLib/lcddraw.o: ../lcdLib/lcddraw.c ../lcdLib/lcdutils.h ../lcdLib/lcddraw.h
	${CC} ${CFLAGS} -c $< -o $@

../lcdLib/lcdutils.o: ../lcdLib/lcdutils.c ../lcdLib/lcdutils.h
	${CC} ${CFLAGS} -c $< -o $@

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf
