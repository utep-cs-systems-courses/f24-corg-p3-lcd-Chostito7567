# Makefile for MSP430 wire game project

CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -O2
TARGET = wire_game
SOURCES = main.c
LOADER = mspdebug
MCU = msp430g2553  # Update this based on your specific MSP430 model
PROGRAMMER = rf2500  # Update this if you're using a different programmer

all: $(TARGET).elf

$(TARGET).elf: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET).elf

load: $(TARGET).elf
	$(LOADER) $(PROGRAMMER) "prog $(TARGET).elf"
