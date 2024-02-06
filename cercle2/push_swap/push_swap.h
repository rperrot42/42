/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:32:39 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/20 16:40:27 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef enum s_operation
{
	PA,
	PB,
	RA,
	RB,
	RR,
	RRR,
	RRA,
	RRB,
	SA,
	SB,
	SS
}	t_operation;

typedef struct s_tab_operation
{
	int			len;
	t_operation	*operations;
}	t_tab_operation;

typedef struct s_stack_info
{
	int	min;
	int	max;
	int	len;
}	t_stack_info;

typedef struct s_all_info
{
	t_tab_stack		*stack_a;
	t_tab_stack		*stack_b;
	t_tab_operation	*tab_operation;
}	t_all_info;

typedef enum s_orderby
{
	ASC,
	DESC
}	t_orderby;

typedef enum s_name_stack
{
	A,
	B,
	ALL
}	t_name_stack;

void			ft_free_error(t_all_info *all_info);
void			ft_free(t_all_info *all_info);
void			ft_init_start(t_all_info *all_info, \
int argc, char **argv, t_bool split);
long int		ft_simpleatoi(char *str);
t_bool			ft_is_in_tab(t_tab_stack *stack_a, int value);
void			ft_swap(t_all_info *all_info, t_name_stack name_stack);
void			ft_push(t_all_info *all_info, t_name_stack name_stack);
void			ft_rotate(t_all_info *all_info, t_name_stack name_stack);
void			ft_rotate_reverse(t_all_info *all_info, \
t_name_stack name_stack);
void			ft_init_rank(t_tab_stack *stack_a);
void			ft_split_a_up(t_all_info *all_info, t_stack_info stack_info);
void			ft_split_b_up(t_all_info *all_info, t_stack_info stack_info);
void			ft_split_b_d(t_all_info *all_info, t_stack_info stack_info);
void			ft_sort_three_nombers(t_all_info *all_info, int len);
void			ft_split_a_d(t_all_info *all_info, t_stack_info stack_info);
void			ft_quicksort_a_up(t_all_info *all_info, \
t_stack_info stack_info, t_bool start);
t_stack_info	ft_create_st_info_max(t_stack_info stack_info);
t_stack_info	ft_crt_st_info_mid(t_stack_info stack_info);
void			ft_quick_sort_b_up(t_all_info *all_info, \
t_stack_info stack_info, t_bool start);
void			ft_quick_sort_a_d(t_all_info *all_info, \
t_stack_info stack_info, t_bool start);
t_stack_info	ft_crt_stack_info_min(t_stack_info stack_info);
void			ft_quick_sort_b_d(t_all_info *all_info, \
t_stack_info stack_info, t_bool start);
void			ft_sort_stack_len_three(t_all_info *all_info);
int				ft_log(int n);
void			ft_add_operation_in_tab(t_tab_operation \
*tab_operation, t_operation operation);
void			ft_print_tab_operations(t_all_info *all_info);
void			ft_optimize_operations(t_tab_operation *tab_operation);
t_bool			ft_checker_bonus(t_all_info *all_info);
#endif