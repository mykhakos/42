NAME = libft.a
HEADER = libft.h

SRC	=	libft_og/ft_atoi.c	\
		libft_og/ft_bzero.c	\
		libft_og/ft_calloc.c		\
		libft_og/ft_isalnum.c	\
		libft_og/ft_isalpha.c	\
		libft_og/ft_isascii.c	\
		libft_og/ft_isdigit.c	\
		libft_og/ft_isprint.c	\
		libft_og/ft_itoa.c		\
		libft_og/ft_memchr.c		\
		libft_og/ft_memcmp.c		\
		libft_og/ft_memcpy.c		\
		libft_og/ft_memmove.c	\
		libft_og/ft_memset.c		\
		libft_og/ft_putchar_fd.c	\
		libft_og/ft_putendl_fd.c	\
		libft_og/ft_putnbr_fd.c	\
		libft_og/ft_putstr_fd.c	\
		libft_og/ft_split.c		\
		libft_og/ft_strchr.c		\
		libft_og/ft_strdup.c		\
		libft_og/ft_striteri.c	\
		libft_og/ft_strjoin.c	\
		libft_og/ft_strlcat.c	\
		libft_og/ft_strlcpy.c	\
		libft_og/ft_strlen.c	\
		libft_og/ft_strmapi.c	\
		libft_og/ft_strncmp.c	\
		libft_og/ft_strnstr.c	\
		libft_og/ft_strrchr.c	\
		libft_og/ft_strtrim.c	\
		libft_og/ft_substr.c		\
		libft_og/ft_tolower.c	\
		libft_og/ft_toupper.c	\
		ft_printf/utils_1.c	\
		ft_printf/utils_2.c	\
		ft_printf/ft_printf.c	\
		get_next_line/ft_find_nl.c  \
		get_next_line/get_next_line.c   \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

