# Compiler and flags
CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -Os

# Source files
SRCS = main.c lcdgame.c led.c buzzer.c switches.c stateMachines.c p2_interrupt_handler.c
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -L./lib -ltimer

# Target executable
TARGET = main.elf

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

load: $(TARGET)
	mspdebug rf2500 "prog $(TARGET)"
