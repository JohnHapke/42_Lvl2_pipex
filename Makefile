# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:35:50 by jhapke            #+#    #+#              #
#    Updated: 2025/02/20 11:49:47 by jhapke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
PROG = pipex

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

all: ${PROG}

${NAME}: ${OBJS}
		$(CC) $(FLAGS) -c $(SOURCE) $(INCLUDES)
		ar rcs ${NAME} ${OBJS}
		ranlib ${NAME}

${PROG}: ${OBJS} ${LIBFT_A}
		$(CC) $(FLAGS) ${OBJS} -L${LIBFT_DIR} -lft -o ${PROG}
		
${LIBFT_A}:
		$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -f ${NAME} ${PROG}
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

%.o: %.c ${HEADER} ${LIBFT_H}
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

.PHONY: all, clean, fclean, re