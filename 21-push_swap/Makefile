NAME = push_swap
CHECKER = checker

SRC = $(wildcard src/input_validation/*.c src/push_swap_ops/*.c src/sorter/*.c src/stack/*.c src/utils/*.c src/main.c) 
CHECK_SRC = $(wildcard src/input_validation/*.c src/push_swap_ops/*.c src/sorter/*.c src/stack/*.c src/utils/*.c src/checker/*.c) 

OBJ = $(SRC:.c=.o)
CHECK_OBJ = ${CHECK_SRC:.c=.o}

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	rm -f $(CHECK_OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make -C libft fclean

re: fclean all

$(CHECKER): $(LIBFT) $(CHECK_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJ) -Llibft -lft

bonus: $(LIBFT) $(CHECK_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJ) -Llibft -lft

.PHONY: all clean fclean re
