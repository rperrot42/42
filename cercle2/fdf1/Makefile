MAKE = make

NAME = fdf

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS =  -g3 -Wall -Werror -Wextra

INClUDE = fdf.h

SRC = create_color.c \
	create_line.c \
	main.c \
	read_file.c  \
	create_point3d.c \
	free_all_info.c \
	alloc_matrix_2d.c \
	transform_in_2d.c \
	print_all_line.c \
	create_rotation_matrix.c \
	display_info.c \
	move.c \
	info_event.c \
	init_distance_pixel.c \
	projection.c

SRC_PATH = src/

CC = gcc

OS := $(shell uname)

SYSTEM_EXPLOIT = uname

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)



$(DIR_OBJS)/%.o: $(SRC_PATH)%.c include/fdf.h| $(DIR_OBJS)
ifeq ($(OS), Linux)
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	$(CC) $(FLAGS) -Imlx -c $< -o $@
endif
$(NAME): $(OBJ)| $(LIBFT)
ifeq ($(OS), Linux)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
else
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
endif
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

