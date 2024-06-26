/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:21:05 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:33 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	ft_rotate_reverse_stack(t_tab_stack *stack_r_r);

void	ft_rotate_reverse(t_all_info *all_info, t_name_stack name_stack, \
t_bool checker)
{
	if (name_stack == A)
	{
		ft_rotate_reverse_stack(all_info -> stack_a);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RRA);
	}
	else if (name_stack == B)
	{
		ft_rotate_reverse_stack(all_info -> stack_b);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RRB);
	}
	else if (name_stack == ALL)
	{
		ft_rotate_reverse_stack(all_info -> stack_a);
		ft_rotate_reverse_stack(all_info -> stack_b);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RRR);
	}
}

static void	ft_rotate_reverse_stack(t_tab_stack *stack_r_r)
{
	int	i;
	int	last_value;
	int	*tab;

	if (stack_r_r -> len > 0)
	{
		tab = stack_r_r->tab_stack;
		i = stack_r_r->len;
		last_value = tab[stack_r_r->len - 1];
		while (--i >= 1)
			tab[i] = tab[i - 1];
		tab[0] = last_value;
	}
}
