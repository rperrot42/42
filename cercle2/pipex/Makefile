MAKE = make

SRC = main.c \
	exec.c \
	pipe.c \
	error.c \
	here_doc.c \
	exec_utils.c

NAME = pipex

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS = -Werror -Wall -Wextra

INClUDES = -Iincludes -Ilibft

FILE_INCLUDES = includes/pipex.h

SRC_PATH = src/

LIBFT_INCLUDE = libft

CC = cc

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

all:$(NAME)

bonus:all

$(NAME): $(OBJ)  $(LIBFT)
	gcc $(FLAGS) $^ -o $@ $(LIBFT)

$(DIR_OBJS)/%.o: $(SRC_PATH)%.c Makefile $(FILE_INCLUDES) | $(DIR_OBJS)
	gcc $(FLAGS) -c $< -o $@ $(INClUDES)

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

re: fclean all

FORCE:

.PHONY: all re clean fclean re FORCE

