MAKE = make

SRC_ALL = ft_free_error.c \
	ft_free.c \
	ft_init_start.c \
	ft_init_rank.c \
	ft_is_in_tab.c \
	ft_push.c \
	ft_rotate_reverse.c \
	ft_rotate.c \
	ft_simpleatoi.c \
	ft_swap.c \
	ft_log.c \
	ft_add_operation_in_tab.c \
	ft_is_tried.c
	

SRC_BONUS = main_bonus.c \
	ft_checker_bonus.c  $(SRC_ALL)

SRC = main.c \
	ft_print_tab_operations.c \
	ft_optimize_operations.c \
	ft_sort_stack_len_three.c \
	ft_split_a_d.c \
	ft_split_a_up.c \
	ft_split_b_up.c \
	ft_split_b_d.c \
	ft_quick_sort_a_up.c \
	ft_quick_sort_a_d.c \
	ft_quick_sort_b_d.c \
	ft_quick_sort_b_up.c  \
	ft_create_st_info_max.c \
	ft_crt_st_info_mid.c \
	ft_sort_three_numbers.c \
	ft_crt_stack_info_min.c $(SRC_ALL)

DIRECTORY_SRC = src/

NAME_BONUS = checker

NAME = push_swap

LIBFT = libft/libft.a

DIR_OBJS = .obj

LIBFT_DIRECTORY = ./libft/

FLAGS = -Werror -Wall -Werror

CC = cc

OBJ = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

OBJ_BONUS = $(addprefix $(DIR_OBJS)/, $(SRC_BONUS:.c=.o))

INCLUDE = include/push_swap.h

all:$(NAME)

bonus: $(NAME_BONUS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIRECTORY)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $@ $(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(LIBFT)

$(DIR_OBJS)/%.o: $(DIRECTORY_SRC)%.c $(INCLUDE) | $(DIR_OBJS)
	$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean: 
	$(MAKE) -C $(LIBFT_DIRECTORY) clean
	rm -rf $(DIR_OBJS)

fclean:
	$(MAKE) -C $(LIBFT_DIRECTORY) fclean
	rm -rf $(DIR_OBJS)
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all re clean fclean bonus

FORCE: