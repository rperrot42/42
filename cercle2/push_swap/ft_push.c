/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:54:08 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:44:38 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_stack(t_tab_stack *stack_add, t_tab_stack *del_tab);

void	ft_push(t_all_info *all_info, t_name_stack name_stack)
{
	if (name_stack == A)
	{
		ft_push_stack(all_info -> stack_a, all_info -> stack_b);
		ft_add_operation_in_tab(all_info -> tab_operation, PA);
	}
	else if (name_stack == B)
	{
		ft_push_stack(all_info -> stack_b, all_info -> stack_a);
		ft_add_operation_in_tab(all_info -> tab_operation, PB);
	}
}

static void	ft_push_stack(t_tab_stack *stack_add, t_tab_stack *del_tab)
{
	ft_add_front_tab(stack_add, ft_del_front_tab(del_tab));
}
