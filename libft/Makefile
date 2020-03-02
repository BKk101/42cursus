# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 16:42:20 by bykim             #+#    #+#              #
#    Updated: 2020/02/29 15:48:35 by bykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror

NAME=libft.a
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

$(NAME) : $(OBJS)
	ar -rc $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all