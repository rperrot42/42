MAKE = make

SRC = main.c \
	exec.c \
	pipe.c

NAME = pipex

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS = -Werror -Wall -Werror

INClUDE = pipex.h


SRC_PATH = src/

CC = cc

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

$(NAME): $(OBJ) | $(LIBFT)
	gcc -g3 $(FLAGS) $^ -o $@ $(LIBFT)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c | $(DIR_OBJS)
	gcc -g3 $(FLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	rm -rf $(DIR_OBJS)
	$(MAKE) -C $(LIBFT_DIRECTORY) clean

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIRECTORY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean re

