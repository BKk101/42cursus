# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 19:11:12 by bykim             #+#    #+#              #
#    Updated: 2020/03/10 16:32:58 by bykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all : $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean :
	rm -f $(OBJS)

re : clean all
