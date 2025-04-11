CC = g++
CFLAGS = -Wall
TARGET = main
SRC = main.cpp
EXTRAS = -lm

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(EXTRAS)

debug:
	$(CC) -g $(CFLAGS) -o $(TARGET) $(SRC) $(EXTRAS)

clean:
	rm -f $(TARGET)

.PHONY: all clean