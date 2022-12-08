LIBNAME = libft.a
HEADER_FOLDER = includes/
SRC_FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
O_FILES = ${SRC_FILES:%.c=%.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${LIBNAME}

${LIBNAME}: ${O_FILES}
	ar rcs ${LIBNAME} ${O_FILES}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:%.c=%.o} -I ${HEADER_FOLDER}

clean:
	rm -f ${O_FILES}

fclean: clean
	rm -f ${LIBNAME}

re: fclean all
