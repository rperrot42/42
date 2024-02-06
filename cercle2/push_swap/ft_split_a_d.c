/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_big_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:50:00 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/20 19:17:05 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_just_split(t_all_info *all_info, \
t_tab_stack *stack_a, int diff_min_max, t_stack_info stack_info);

void	ft_split_a_d(t_all_info *all_info, t_stack_info stack_info)
{
	int			i;
	int			diff_min_max;
	t_tab_stack	*stack_a;

	i = -1;
	stack_a = all_info->stack_a;
	diff_min_max = stack_info.max - stack_info.min + 1;
	while (++i < stack_info.len)
		ft_just_split(all_info, stack_a, diff_min_max, stack_info);
}

static void	ft_just_split(t_all_info *all_info, \
t_tab_stack *stack_a, int diff_min_max, t_stack_info stack_info)
{
	int	*tab_a;

	tab_a = stack_a -> tab_stack;
	if (tab_a[stack_a -> len - 1] < stack_info.min + diff_min_max \
	/ 3 && tab_a[stack_a -> len - 1] < stack_info.max - 5)
	{
		ft_rotate_reverse(all_info, A);
		ft_push(all_info, B);
		ft_rotate(all_info, B);
	}
	else if (tab_a[stack_a -> len - 1] < stack_info.min + diff_min_max / 3 * \
2 + (diff_min_max % 3 >= 1) && tab_a[stack_a -> len - 1] < stack_info.max - 2)
	{
		ft_rotate_reverse(all_info, A);
		ft_push(all_info, B);
	}
	else
		ft_rotate_reverse(all_info, A);
}
