/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_b_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:59:36 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:54 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	ft_just_split(t_all_info *all_info, \
t_tab_stack *stack_b, int diff_min_max, t_stack_info stack_info);

void	ft_split_b_d(t_all_info *all_info, t_stack_info stack_info)
{
	int			i;
	int			diff_min_max;
	t_tab_stack	*stack_b;

	i = -1;
	stack_b = all_info -> stack_b;
	diff_min_max = stack_info.max - stack_info.min + 1;
	while (++i < stack_info.len)
		ft_just_split(all_info, stack_b, diff_min_max, stack_info);
}

static void	ft_just_split(t_all_info *all_info, \
t_tab_stack *stack_b, int diff_min_max, t_stack_info stack_info)
{
	int	*tab_b;

	tab_b = stack_b -> tab_stack;
	if (tab_b[stack_b->len - 1] < stack_info.min + diff_min_max \
	/ 3 && tab_b[stack_b->len - 1] < stack_info.max - 5)
		ft_rotate_reverse(all_info, B, FALSE);
	else if (tab_b[stack_b->len - 1] < stack_info.min + diff_min_max / 3 * 2 \
	+ (diff_min_max % 3 >= 1) && tab_b[stack_b->len - 1] < stack_info.max - 2)
	{
		ft_rotate_reverse(all_info, B, FALSE);
		ft_push(all_info, A, FALSE);
		ft_rotate(all_info, A, FALSE);
	}
	else
	{
		ft_rotate_reverse(all_info, B, FALSE);
		ft_push(all_info, A, FALSE);
	}
}
