# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:35:50 by jhapke            #+#    #+#              #
#    Updated: 2025/03/18 11:33:39 by jhapke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCE =	pipex.c\
			pipex_utils.c\

SOURCE_B =	pipex_bonus.c\
			pipex_utils_bonus.c\

OBJS =		$(SOURCE:.c=.o)
OBJS_B =	$(SOURCE_B:.c=.o)

FLAGS = -Werror -Wall -Wextra

CC = gcc

HEADER = 	pipex.h
HEADER_B =	pipex_bonus.h

LIBFT_DIR = libft
LIBFT_H = $(LIBFT_DIR)/libft.h
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(HEADER)
		$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
		
bonus: $(OBJS_B) $(LIBFT_A) $(HEADER_B)
		$(CC) $(FLAGS) $(INCLUDES) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $(NAME)

${LIBFT_A}:
		$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ${HEADER} ${LIBFT_H}
		$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
		rm -rf ${OBJS} ${OBJS_B}

fclean: clean
		rm -f ${NAME}
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re