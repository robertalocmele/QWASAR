CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c game_logic.c utils.c
OBJ = $(SRC:.c=.o)
EXEC = my_mastermind

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
