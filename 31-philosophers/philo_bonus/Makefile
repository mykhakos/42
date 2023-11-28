NAME = philo_bonus

SRC = $(shell find ./src -name '*.c')
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
