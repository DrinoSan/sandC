# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source files
SRCS = vector.c main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = vector.h

# Name of the executable
TARGET = vector_program

# Default target
all: $(TARGET)

# Rule to create the executable from object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up rule
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
