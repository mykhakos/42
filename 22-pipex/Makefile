NAME = pipex

SRC = $(shell find ./src -name '*.c')
SRC_BONUS = $(shell find ./src_bonus -name '*.c')

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR_PATH = lib/libft
LIBFT_LIB_FILE = libft.a
LIBFT = $(LIBFT_DIR_PATH)/$(LIBFT_LIB_FILE)

BIN_DIR = bin
BIN_BONUS_DIR = $(BIN_DIR)/bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(LIBFT) $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o  $(BIN_DIR)/$(NAME) $(OBJ) -L$(LIBFT_DIR_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR_PATH)

bonus: $(BIN_BONUS_DIR)/$(NAME)

$(BIN_BONUS_DIR)/$(NAME): $(LIBFT) $(OBJ_BONUS)
	mkdir -p $(BIN_DIR)
	mkdir -p $(BIN_BONUS_DIR)
	$(CC) $(CFLAGS) -o $(BIN_BONUS_DIR)/$(NAME) $(OBJ_BONUS) -L$(LIBFT_DIR_PATH) -lft

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_DIR_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR_PATH) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
