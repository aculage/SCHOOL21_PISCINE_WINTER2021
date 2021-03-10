NAME = libft.a
HEADERS_DIR = includes/
HEADERS = $(addprefix ${HEADERS_DIR}, ft.h)
SRCS_DIR = srcs/
SRCS = $(addprefix ${SRCS_DIR}, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I ${HEADERS_DIR} 
RAN = ranlib
ARFLAGS = rc
TMP = ${SRCS:.c=.c~}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: ${NAME}

${NAME}: 	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS}
			${RAN} ${NAME}

clean:
	${RM} ${TMP}
fclean: clean
	${RM} ${OBJS}
re: fclean all
