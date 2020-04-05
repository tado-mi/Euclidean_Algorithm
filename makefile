# the compiler
CC = gcc

# compiler flags
# -g	add debugging info to the executable
# -Wall	turn on (most) compiler warnings
CFLAGS = -g -Wall

TARGET = main
OUTFILE = main.o

# data-struct is a separate repo
# clone & adjust paths accordingly
DATA_STRUCTS = ../data-struct/src

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGE) $(DATA_STRUCTS)/*.c *.c -o $(OUTFILE)

run:
	./$(OUTFILE)

clean:
	$(RM) $(OUTFILE)
