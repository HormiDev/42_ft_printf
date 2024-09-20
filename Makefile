# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 14:52:03 by ide-dieg          #+#    #+#              #
#    Updated: 2024/09/20 23:52:06 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_strlen_int.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putnbr_base_p.c \
		ft_putstr.c \
			
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -crs  $@ $?

%.o : %.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : clean fclean