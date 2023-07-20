CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = piggy_bank

.PHONY: all clean

all: banner $(TARGET)

banner:
	@echo "----------------------------------------"
	@echo "      Welcome to Piggy Bank Makefile    "
	@echo "----------------------------------------"

$(TARGET): main.o
	$(CC) $(CFLAGS) main.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
