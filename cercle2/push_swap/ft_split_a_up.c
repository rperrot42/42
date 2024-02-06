/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_in_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:54:50 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/20 19:13:38 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_a_up(t_all_info *all_info, t_stack_info stack_info)
{
	int			i;
	int			diff_min_max;
	int			*tab_a;
	t_tab_stack	*stack_a;

	i = -1;
	stack_a = all_info -> stack_a;
	diff_min_max = stack_info.max - stack_info.min + 1;
	tab_a = stack_a -> tab_stack;
	while (++i < stack_info.len)
	{
		if (*tab_a < stack_info.min + diff_min_max / 3 \
		&& *tab_a < stack_info.max - 5)
		{
			ft_push(all_info, B);
			ft_rotate(all_info, B);
		}
		else if (*tab_a < stack_info.min + diff_min_max / 3 * 2 + \
		(diff_min_max % 3 >= 1) && *tab_a < stack_info.max - 2)
			ft_push(all_info, B);
		else
			ft_rotate(all_info, A);
	}
}
