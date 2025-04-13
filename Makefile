CC = g++
CFLAGS = -Wall
TARGET = main
SRC = main.cpp
EXTRAS = -lm

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(EXTRAS)

debug:
	$(CC) -g -O0 $(CFLAGS) -o $(TARGET) $(SRC) $(EXTRAS)

clean:
	rm -f $(TARGET)

.PHONY: all clean