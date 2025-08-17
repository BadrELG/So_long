# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badr <badr@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 09:55:00 by badr              #+#    #+#              #
#    Updated: 2025/08/18 00:37:53 by badr             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = test.c

OBJS = ${SRCS:.c=.o}

LIBFT = libft
LIBFT_A = ${LIBFT}/libft.a

MLX = mlx
MLX_A = ${MLX}/libmlx.a

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	make -C ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_A} ${MLX_A} -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT}
	make clean -C ${MLX}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT}
	make clean -C ${MLX}

re: fclean all

.PHONY: all clean fclean re
