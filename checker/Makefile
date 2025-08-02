CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 \
         -Imain -Iutils -Itypewriter -Ivalidators -Ivalidators/linters \
         -Ivalidators/basics -Ivalidators/hash \
         -DOPENSSL_API_COMPAT=0x30000000L -Wno-deprecated-declarations

DIRS = main utils typewriter validators validators/linters validators/basics validators/hash logs
SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))

OBJ = $(SRC:.c=.o)
BIN = checker

.PHONY: all clean fclean re run

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -ljson-c -lssl -lcrypto

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN)

re: fclean all
