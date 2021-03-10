NAME = pnum
HEADERS_DIR = include/
HEADERS = $(addprefix ${HEADERS_DIR}, ft.h ft_dict.h ft_list.h ft_fparser.h)
SRCS_DIR = srcs/
SRCS = $(addprefix ${SRCS_DIR}, *)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I ${HEADERS_DIR} 
TMP = ${SRCS:.c=.c~}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: 	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${TMP}

fclean: clean
	${RM} ${OBJS}

re: fclean all
