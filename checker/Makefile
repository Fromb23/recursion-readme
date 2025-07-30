CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Itypewriter -Ivalidators
SRC = $(wildcard *.c typewriter/*.c validators/*.c)
OBJ = $(SRC:.c=.o)
DEPS = checker.h validators/validators.h
BIN = checker

.PHONY: all clean fclean re run

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -ljson-c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN)

re: fclean all
