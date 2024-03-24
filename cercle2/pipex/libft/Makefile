SRC = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putchar_fd.c \
		ft_printf/ft_putnbr_base_long.c \
		ft_printf/ft_putnbr_fd.c \
		ft_printf/ft_putstr_fd.c \
		ft_printf/ft_strlen.c \
		ft_addstack.c \
		ft_stackfirst.c \
		ft_delstack.c \
		ft_stackinit.c \
		ft_stackfree.c \
		ft_crt_elmnt_stack.c \
		ft_lenstack.c \
		ft_add_front_tab.c \
		ft_del_front_tab.c \
		get_next_line.c \
		get_next_line_utils.c

DIR_OBJS = .obj

NAME = libft.a

CC = cc

FLAGS = -Werror -Wall -Wextra

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

INCLUDE = libft.h ft_printf/ft_printf.h

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

all:$(NAME)

$(DIR_OBJS)/%.o: %.c $(INCLUDE) Makefile | $(DIR_OBJS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJS)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p $(DIR_OBJS)/ft_printf

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean