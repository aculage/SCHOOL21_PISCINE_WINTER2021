# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:06:06 by acami             #+#    #+#              #
#    Updated: 2021/03/10 20:12:23 by hbrendon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq
SRC_D	=	./srcs/
INCL_D	=	./includes/
SRC_F	=	main.c ft_bsq.c ft_parser.c ft_print.c ft_error.c ft.c ft_file_operators.c ft_parser2.c ft_parser3.c
SRCS	=	${addprefix ${SRC_D}, ${SRC_F}}
OBJS	=	${SRCS:.c=.o}
TMP_F	=	${SRCS:.c=.c~}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ${INCL_D}
RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			
${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

debug:		
			${CC} -g ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} ${TMP}

fclean:		clean
			${RM} ${OBJS}

re:			fclean all

.PHONY:		all clear fclean re