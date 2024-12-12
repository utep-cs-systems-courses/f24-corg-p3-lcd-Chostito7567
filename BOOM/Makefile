# Makefile for MSP430 wire game project

# Compiler and flags
CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -O2 -Wall

# Debugger and programmer
LOADER = mspdebug
PROGRAMMER = rf2500  # Update this to your specific programmer (e.g., tilib, usb)

# Targets
TARGET = wire_game
SOURCES = main.c

# Default target
all: $(TARGET).elf

# Rule to build the ELF file
$(TARGET).elf: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target to remove generated files
clean:
	rm -f $(TARGET).elf

# Load target to flash the program to the MSP430
load: $(TARGET).elf
	$(LOADER) $(PROGRAMMER) "prog $(TARGET).elf"

# Debugging target (optional, for stepping through the program)
debug: $(TARGET).elf
	$(LOADER) $(PROGRAMMER) "load $(TARGET).elf"
