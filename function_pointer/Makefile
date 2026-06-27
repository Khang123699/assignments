# --- Toolchain Configuration ---
CC = gcc

# CFLAGS: Compiler options
CFLAGS = -Wall -Wextra -g

# --- Project Configuration ---
TARGET = function_pointer_test

# --- Build Rules ---
.PHONY: all clean

# Default target built when running `make`
all: $(TARGET)

# Rule to link and build the target executable
$(TARGET): function_pointer.c unit_test.c function_pointer.h
	$(CC) $(CFLAGS) function_pointer.c unit_test.c -o $(TARGET)

# Rule to remove generated build artifacts
clean:
	rm -f $(TARGET)
