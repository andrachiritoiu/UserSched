CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

TARGET = usersched

SRC = src/main.c src/scheduler.c src/process.c src/stats.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET) tests/test_basic.c
	$(CC) $(CFLAGS) -o test_runner tests/test_basic.c src/scheduler.c src/process.c src/stats.c
	./test_runner

clean:
	rm -f $(TARGET) test_runner $(OBJ)
