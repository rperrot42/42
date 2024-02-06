/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_b_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:59:46 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:49:11 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_b_up(t_all_info *all_info, \
t_stack_info stack_info, t_bool start)
{
	int	i;

	if (stack_info.len <= 3)
	{
		i = -1;
		while (++i < stack_info.len)
			ft_push(all_info, A);
		ft_sort_three_nombers(all_info, stack_info.len);
	}
	else
	{
		ft_split_b_up(all_info, stack_info);
		ft_quicksort_a_up(all_info, ft_create_st_info_max(stack_info), start);
		ft_quick_sort_a_d(all_info, ft_crt_st_info_mid(stack_info), start);
		ft_quick_sort_b_d(all_info, ft_crt_stack_info_min(stack_info), start);
	}
}
