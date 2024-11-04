CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c game_logic.c utils.c
OBJ = $(SRC:.c=.o)

EXEC = my_mastermind

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)  # This line MUST be indented with a tab

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  # This line MUST be indented with a tab

clean:
	rm -f $(OBJ)  # This line MUST be indented with a tab

fclean: clean
	rm -f $(EXEC)  # This line MUST be indented with a tab

re: fclean all
