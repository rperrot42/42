/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:54:08 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:18 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	ft_push_stack(t_tab_stack *stack_add, t_tab_stack *del_tab);

void	ft_push(t_all_info *all_info, t_name_stack name_stack, t_bool checker)
{
	if (name_stack == A)
	{
		ft_push_stack(all_info -> stack_a, all_info -> stack_b);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, PA);
	}
	else if (name_stack == B)
	{
		ft_push_stack(all_info -> stack_b, all_info -> stack_a);
		if (checker == FALSE)
			ft_add_operation_in_tab(all_info -> tab_operation, PB);
	}
}

static void	ft_push_stack(t_tab_stack *stack_add, t_tab_stack *del_tab)
{
	if (del_tab -> len > 0)
		ft_add_front_tab(stack_add, ft_del_front_tab(del_tab));
}
