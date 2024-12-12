CC = msp430-elf-gcc
CFLAGS = -mmcu=msp430g2553 -I./h
SRCS = main.c stateMachines.c led.c switches.c buzzer.c libTimer.c
OBJS = $(SRCS:.c=.o)
TARGET = main.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
load: $(TARGET)
    mspdebug rf2500 "prog $(TARGET)"

clean:
	rm -f $(OBJS) $(TARGET)
