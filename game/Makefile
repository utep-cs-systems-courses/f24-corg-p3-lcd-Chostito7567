CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -Os
TARGET = main.elf

SRC = main.c lcdutils.c lcddraw.c switches.c buzzer.c stateMachines.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

load: $(TARGET)
	mspdebug rf2500 "prog $(TARGET)"
