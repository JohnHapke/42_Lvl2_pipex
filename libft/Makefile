# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 15:55:53 by jhapke            #+#    #+#              #
#    Updated: 2024/12/26 15:55:53 by jhapke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c \
		ft_printf_character.c\
		ft_printf_decimal.c\
		ft_printf_hexadecimal_low.c\
		ft_printf_hexadecimal_up.c\
		ft_printf_percent.c\
		ft_printf_pointer.c\
		ft_printf_string.c\
		ft_printf_unsigned.c\
		ft_printf.c\

SOURCE_B = 	ft_lstadd_back.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstsize.c\

OBJS = $(SOURCE:.c=.o)

OBJS_B = $(SOURCE_B:.c=.o)

FLAGS = -Werror -Wall -Wextra

CC = gcc

HEADER = libft.h

all: $(NAME)

$(NAME): 
		$(CC) $(FLAGS) -c $(SOURCE)
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)

bonus: $(OBJS_B)
		$(AR) -r $(NAME) $?
%.o: %.c
		$(CC) -o $@ -c $(FLAGS) $<

clean:
		rm -rf $(OBJS) $(OBJS_B)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
