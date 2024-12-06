# Compiler and linker
CC = msp430-gcc

# MCU model - replace with your specific MSP430 model
MCU = msp430g2553

# Compiler flags
CFLAGS = -mmcu=$(MCU) -O2 -Wall -I.

# Source files
SRC = main.c lcdutils.c lcddraw.c font-5x7.c font-8x12.c font-11x16.c

# Object files (derived from source files)
OBJ = $(SRC:.c=.o)

# Output file
TARGET = simon_game.elf

# Default rule: build the target
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Load the program onto the MSP430
load: $(TARGET)
	mspdebug rf2500 "load $(TARGET)"
