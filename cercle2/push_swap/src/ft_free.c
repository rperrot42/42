/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:38:19 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:19:55 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_free(t_all_info *all_info)
{
	t_tab_stack	*stack_a;
	t_tab_stack	*stack_b;

	stack_a = all_info -> stack_a;
	stack_b = all_info -> stack_b;
	if (stack_a && stack_a->tab_stack)
		free(stack_a->tab_stack);
	if (stack_b && stack_b->tab_stack)
		free(stack_b->tab_stack);
	if (all_info->tab_operation && all_info -> tab_operation->operations)
		free(all_info -> tab_operation->operations);
	if (stack_b)
		free(stack_b);
	if (stack_a)
		free(stack_a);
	if (all_info->tab_operation)
		free(all_info->tab_operation);
	free(all_info);
}
