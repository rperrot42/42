/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:00:58 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:21:00 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	ft_swap_stack(t_tab_stack *stack_swap);

void	ft_swap(t_all_info *all_info, t_name_stack name_stack, t_bool checker)
{
	if (name_stack == A)
	{
		ft_swap_stack(all_info -> stack_a);
		ft_add_operation_in_tab(all_info -> tab_operation, SA);
	}
	else if (name_stack == B)
	{
		ft_swap_stack(all_info -> stack_b);
		ft_add_operation_in_tab(all_info -> tab_operation, SB);
	}
	else if (name_stack == ALL)
	{
		ft_swap_stack(all_info -> stack_b);
		ft_swap_stack(all_info -> stack_a);
	}
}

void	ft_swap_stack(t_tab_stack *stack_swap)
{
	int	swap;
	int	*tab;

	tab = stack_swap -> tab_stack;
	if (stack_swap -> len >= 2)
	{
		swap = tab[0];
		tab[0] = tab[1];
		tab[1] = swap;
	}
}
