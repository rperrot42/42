/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:21:05 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:36 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	ft_rotate_stack(t_tab_stack *stack_rotate);

void	ft_rotate(t_all_info *all_info, t_name_stack name_stack, t_bool checker)
{
	if (name_stack == A)
	{
		ft_rotate_stack(all_info -> stack_a);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RA);
	}
	else if (name_stack == B)
	{
		ft_rotate_stack(all_info -> stack_b);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RB);
	}
	else if (name_stack == ALL)
	{
		ft_rotate_stack(all_info -> stack_a);
		ft_rotate_stack(all_info -> stack_b);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, RRR);
	}
}

static void	ft_rotate_stack(t_tab_stack *stack_rotate)
{
	int	i;
	int	first_value;
	int	*tab;
	int	len;

	if (stack_rotate -> len > 0)
	{
		tab = stack_rotate -> tab_stack;
		len = stack_rotate -> len;
		i = -1;
		first_value = tab[0];
		while (++i < len - 1)
			tab[i] = tab[i + 1];
		tab[i] = first_value;
	}
}
