# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:27:38 by fvarrin           #+#    #+#              #
#   Updated: 2022/02/17 17:41:59 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

# DIRS
ROOT_DIR		?= $(shell pwd)
SRC_DIR			= ${ROOT_DIR}/srcs/
HEADER_DIR		= ${ROOT_DIR}/includes/
LIBFT_DIR		= ${ROOT_DIR}/libft/
MLX_DIR			= ${ROOT_DIR}/minilibx-wrapper/

# COMPILER
SRC			= $(addprefix ${SRC_DIR}, main.c init.c draw.c line.c parse.c handle.c \
				projection.c destroy.c debug.c utils.c camera.c boundaries.c mover.c)
OBJ			= $(SRC:.c=.o)
NAME 			= fdf
NORM_BIN		= norminette
NORM_FLAGS		= -RCheckForbiddenSourceHeader -RCheckDefine
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I${HEADER_DIR} -I${LIBFT_DIR}includes -I${MLX_DIR}includes -g
CC			= gcc
LIBFT_FLAGS		= -L${LIBFT_DIR} -lft
BUFFER_SIZE		= 1024
UNAME_S			:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_FLAGS	= -L${MLX_DIR} -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS	= -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
endif

.PHONY: 	all clean fclean re

${NAME}:	${OBJ}
			@make -C ${LIBFT_DIR} BUFFER_SIZE=${BUFFER_SIZE} all || true
			@make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${OBJ} ${LIBFT_FLAGS} ${MLX_FLAGS} -o ${NAME}

all: 		${NAME}

clean:
		${RM} ${OBJ}
		@make -C ${LIBFT_DIR} clean || true
		@make -C ${MLX_DIR} clean || true
		${RM} ${TEST_OBJ}

fclean: 	clean
		@make -C ${LIBFT_DIR} fclean || true
		${RM} ${NAME}
		${RM} ${TEST_NAME}

re:		fclean ${NAME}

norm:		fclean
		echo "\n\n"
		${NORM_BIN} ${NORM_FLAGS} ${SRC}
