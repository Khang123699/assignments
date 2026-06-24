CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = memory_pool_test

.PHONY: all clean

all: $(TARGET)

$(TARGET): memory_pool.c unit_test.c memory_pool.h
	$(CC) $(CFLAGS) memory_pool.c unit_test.c -o $(TARGET)

clean:
	rm -f $(TARGET)
