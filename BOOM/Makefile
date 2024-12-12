# makfile configuration

CPU             	= msp430g2553

CFLAGS          	= -mmcu=${CPU} -Os -I../h

LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-gcc -mmcu=${CPU} -c



all:main.elf



#additional rules for files

main.elf: ${COMMON_OBJECTS} main.o main.o buzzer.o led.o switches.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 



load: main.elf

	msp430loader.sh $^



clean:

	rm -f *.o *.elf
