MAKE = make

NAME = fdf

LIBFT = libft/libft.a

DIR_OBJS = .obj

INCLUDE_DIR = includes

LIBFT_DIRECTORY = ./libft/

FLAGS =  -g3 -Wall -Werror -Wextra

INClUDE = $(INCLUDE_DIR)/fdf.h

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
	projection.c \
	matrix_utils.c \
	init_all_info.c

SRC_PATH = src/

CC = gcc

OS := $(shell uname)

SYSTEM_EXPLOIT = uname

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

IFLAGS = -I libft \
			-I $(INCLUDE_DIR)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c $(INClUDE) | $(DIR_OBJS)
ifeq ($(OS), Linux)
	$(CC)  $(IFLAGS) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	$(CC)  $(IFLAGS) $(FLAGS) -Imlx -c $< -o $@
endif
$(NAME): $(OBJ) $(LIBFT)
ifeq ($(OS), Linux)
	$(CC) $(OBJ)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
else
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
endif
$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	rm -rf $(DIR_OBJS)
	$(MAKE) -C $(LIBFT_DIRECTORY) clean

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIRECTORY)

fclean:
	rm -f $(NAME)
	rm -rf $(DIR_OBJS)
	$(MAKE) -C $(LIBFT_DIRECTORY) fclean

FORCE:

re: fclean all

.PHONY: all re clean fclean re FORCE

