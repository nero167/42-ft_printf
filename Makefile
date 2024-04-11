# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 12:43:39 by namirtha          #+#    #+#              #
#    Updated: 2024/04/11 15:26:34 by namirtha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CCFLAGS = -Wextra -Werror -Wall
SRCS = \
ft_printf.c \
ft_printchar.c \
ft_printhex.c \
ft_printint.c \
ft_printptr.c \
ft_printstr.c \
ft_printunsigned.c \
ft_printptr_addr.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all fclean clean re