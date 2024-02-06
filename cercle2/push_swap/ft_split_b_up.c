/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:09:42 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/20 19:16:26 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_b_up(t_all_info *all_info, t_stack_info stack_info)
{
	int			i;
	int			diff_min_max;
	int			*tab_b;
	t_tab_stack	*stack_b;

	i = -1;
	stack_b = all_info -> stack_b;
	diff_min_max = stack_info.max - stack_info.min + 1;
	tab_b = stack_b -> tab_stack;
	while (++i < stack_info.len)
	{
		if (*tab_b < stack_info.min + diff_min_max / 3 && *tab_b < \
		stack_info.max - 5)
			ft_rotate(all_info, B);
		else if (*tab_b < stack_info.min + diff_min_max / 3 * 2 + \
		(diff_min_max % 3 >= 1) && *tab_b < stack_info.max - 2)
		{
			ft_push(all_info, A);
			ft_rotate(all_info, A);
		}
		else
			ft_push(all_info, A);
	}
}
