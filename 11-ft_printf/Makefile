NAME = libftprintf.a

SRCS = src/ft_printf.c \
	   src/utils_1.c \
	   src/utils_2.c

OBJS = $(SRCS:.c=.o)

INC = -I include

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: main.c $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o main

clean:
	rm -f $(OBJS) main.o

fclean: clean
	rm -f $(NAME) main

re: fclean all

.PHONY: all clean fclean re