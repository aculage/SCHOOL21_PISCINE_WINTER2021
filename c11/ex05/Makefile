NAME = do-op
HEADERS_DIR = ./
HEADERS = $(addprefix ${HEADERS_DIR}, )
SRCS_DIR = ./
SRCS = $(addprefix ${SRCS_DIR}, ft_doop.c ft_func.c ft_atoi.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I ${HEADERS_DIR} 
TMP = ${SRCS:.c=.c~}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.SILENT:

all: ${NAME}

${NAME}: ${SRCS}
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME}
clean:
	@${RM} ${TMP}
fclean: clean
	@${RM} ${OBJS}
re: fclean all

