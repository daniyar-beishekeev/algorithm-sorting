CC = g++
CFLAGS = -Wall
TARGET = gen
SRC = gen.cpp
EXTRAS = -lm

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(EXTRAS)

clean:
	rm -f $(TARGET)

.PHONY: all clean