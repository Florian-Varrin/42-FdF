# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:27:38 by fvarrin           #+#    #+#              #
#    Updated: 2021/12/06 11:54:26 by fvarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR		?= $(shell pwd)
SRC_DIR			= ${ROOT_DIR}/srcs/
HEADER_DIR		= ${ROOT_DIR}/includes/
LIBFT_DIR		= ${ROOT_DIR}/libft/
SRC			= $(addprefix ${SRC_DIR}, main.c)
OBJ			= $(SRC:.c=.o)
NAME 			= fdf
NORM_BIN		= norminette
NORM_FLAGS		= -RCheckForbiddenSourceHeader -RCheckDefine
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I${HEADER_DIR} -I${LIBFT_DIR}/includes
CC			= gcc
LIBFT_FLAGS		= -L${LIBFT_DIR} -lft

.PHONY: 	all clean fclean re

${NAME}:	${OBJ}
		@make -C ${LIBFT_DIR} all || true
		${CC} ${CFLAGS} ${OBJ} ${LIBFT_FLAGS} -o ${NAME}

all: 		${NAME}

clean:
		${RM} ${OBJ}
		${RM} ${TEST_OBJ}

fclean: 	clean
		@make -C libft fclean || true
		${RM} ${NAME}
		${RM} ${TEST_NAME}

re:		fclean ${NAME}

norm:		fclean
		echo "\n\n"
		${NORM_BIN} ${NORM_FLAGS} ${SRC}
