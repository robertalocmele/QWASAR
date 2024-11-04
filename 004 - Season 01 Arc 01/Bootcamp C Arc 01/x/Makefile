# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = main.c game_logic.c utils.c
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = my_mastermind

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)  # This line MUST be indented with a tab

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  # This line MUST be indented with a tab

# Clean up object files and executable
clean:
	rm -f $(OBJ)  # This line MUST be indented with a tab

# Clean up and remove executable
fclean: clean
	rm -f $(EXEC)  # This line MUST be indented with a tab

# Rebuild the project
re: fclean all
