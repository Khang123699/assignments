# --- Toolchain Configuration ---
CC = gcc

# CFLAGS: Compiler options
CFLAGS = -Wall -Wextra -g

# --- Project Configuration ---
TARGET = ring_buffer_test

# --- Build Rules ---
.PHONY: all clean

# Default target built when running `make`
all: $(TARGET)

# Rule to link and build the target executable
$(TARGET): ring_buffer.c unit_test.c ring_buffer.h
	$(CC) $(CFLAGS) ring_buffer.c unit_test.c -o $(TARGET)

# Rule to remove generated build artifacts
clean:
	rm -f $(TARGET)