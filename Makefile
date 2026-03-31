# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 17:59:03 by bayseven          #+#    #+#              #
#    Updated: 2026/03/30 22:20:03 by bayseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS 	= ft_printf.c ft_print_simple.c ft_print_hex.c
OBJS    = $(SRCS:.c=.o)
AR      = ar rcs
RM      = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
