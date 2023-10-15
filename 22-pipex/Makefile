NAME = pipex

SRC = $(shell find ./src -name '*.c')

OBJ = $(SRC:.c=.o)

LIBFT_DIR_PATH = lib/libft
LIBFT_LIB_FILE = libft.a
LIBFT = $(LIBFT_DIR_PATH)/$(LIBFT_LIB_FILE)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR_PATH)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
