SRC = ft_printf.c ft_putchr.c ft_putstr.c ft_putnbr.c ft_put_adr.c ft_hexanbr.c

OBJS = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBC = ar -rc
RM = rm -f 

all: ${NAME}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all