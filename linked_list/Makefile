# --- Toolchain Configuration ---
CC = gcc

# CFLAGS: Compiler options
CFLAGS = -Wall -Wextra -g

# --- Project Configuration ---
TARGET = linked_list_test

# --- Build Rules ---
.PHONY: all clean

# Default target built when running `make`
all: $(TARGET)

# Rule to link and build the target executable
$(TARGET): linked_list.c unit_test.c linked_list.h
	$(CC) $(CFLAGS) linked_list.c unit_test.c -o $(TARGET)

# Rule to remove generated build artifacts
clean:
	rm -f $(TARGET)