NAME = ft_display_file
HEADERS_DIR = ./
HEADERS = $(addprefix ${HEADERS_DIR}, ft_file.h)
SRCS_DIR = ./
SRCS = $(addprefix ${SRCS_DIR}, ft_display_file.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I ${HEADERS_DIR} 
RAN = ranlib
ARFLAGS = rc
TMP = ${SRCS:.c=.c~}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	

all: ${NAME}

${NAME}: ${OBJS} 	
		${CC} ${CFLAGS} ${SRCS} -o ${NAME}
		
clean:
	${RM} ${TMP}
fclean: clean
	${RM} ${OBJS}
re: fclean all
