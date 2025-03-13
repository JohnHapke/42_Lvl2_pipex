# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:35:50 by jhapke            #+#    #+#              #
#    Updated: 2025/03/06 10:06:29 by jhapke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCE =	pipex.c\
			pipex_utils.c\

OBJS =		$(SOURCE:.c=.o)
MAIN =		pipex.c

FLAGS = -Werror -Wall -Wextra

CC = gcc

HEADER = pipex.h

LIBFT_DIR = libft
LIBFT_H = $(LIBFT_DIR)/libft.h
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR)

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_A}
		$(CC) $(FLAGS) ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}
		
${LIBFT_A}:
		$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ${HEADER} ${LIBFT_H}
		$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -f ${NAME}
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re