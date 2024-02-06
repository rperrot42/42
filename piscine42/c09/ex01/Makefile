# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 15:23:37 by rperrot           #+#    #+#              #
#    Updated: 2023/07/26 15:25:45 by rperrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_putchar.c \
	  srcs/ft_swap.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strlen.c \
	  srcs/ft_strcmp.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

INCLUDES = -I includes/

$(NAME):$(OBJ)
	ar rcs $(NAME) srcs/*.o

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)

re: fclean $(NAME)
