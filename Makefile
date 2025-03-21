CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = test
SRC = sslog.c test.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) test.log

run: $(TARGET)
	./$(TARGET)
