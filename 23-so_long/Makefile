NAME = so_long

SRC = $(shell find ./src -name '*.c')

OBJ = $(SRC:.c=.o)

LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_LIB_FILE = $(LIBFT_DIR)/libft.a
MLX_DIR = $(LIB_DIR)/mlx
MLX_LIB_FILE = $(LIBFT_DIR)/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB_FILE) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB_FILE):
	make -C $(LIBFT_DIR)

$(MLX_LIB_FILE):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re
