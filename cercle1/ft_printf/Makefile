SRC = ft_putnbr_base_long.c \
		ft_printf.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_putchar_fd.c

NAME = libftprintf.a

GCC = cc

FLAGS = -Werror -Wall -Wextra

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all:$(NAME)

%.o: %.c $(INCLUDE)
	$(GCC) $(FLAGS) -I/$(INCLUDE) -c $< -o $@

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJB)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean