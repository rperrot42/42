# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 22:57:33 by rperrot           #+#    #+#              #
#    Updated: 2023/07/27 15:38:05 by rperrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	  ft_putnbr.c \
	  logical_operator.c \
	  main.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = do-op

OBJ = $(SRC:.c=.o)

all: $(SRC) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

fclean:
	rm -rf $(NAME)
clean:
	rm -rf *.o
