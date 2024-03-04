MAKE = make

NAME = fdf

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS = -Werror -Wall -Wextra

INClUDE = fdf.h

SRC = create_color.c create_line.c main.c read_file.c

SRC_PATH = src/

CC = cc

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c | $(DIR_OBJS)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME): $(OBJ)| $(LIBFT)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

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

