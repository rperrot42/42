MAKE = make

NAME = fdf

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS = -Werror -Wall -Werror

INClUDE = fdf.h

SRC = create_color.c create_line.c

SRC_PATH = src/

CC = cc

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

$(NAME): $(OBJ) | $(LIBFT)
	gcc $(FLAGS) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit src/main.c $^ -o $@ $(LIBFT)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c | $(DIR_OBJS)
	gcc $(FLAGS) -I /usr/X11/include  -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	rm -rf $(DIR_OBJS)
	$(MAKE) -C $(LIBFT_DIRECTORY) clean

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIRECTORY)

fclean:
	rm -f $(NAME)
	rm -rf $(DIR_OBJS)
	$(MAKE) -C $(LIBFT_DIRECTORY) fclean

re: fclean all

.PHONY: all re clean fclean re

