/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_a_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:18:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:24 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_quicksort_a_up(t_all_info *all_info, \
t_stack_info stack_info, t_bool start)
{
	if (stack_info.len <= 3)
	{
		if (all_info -> stack_a -> len <= 3)
			ft_sort_stack_len_three(all_info);
		else
			ft_sort_three_nombers(all_info, stack_info.len);
	}
	else
	{
		ft_split_a_up(all_info, stack_info);
		if (start == TRUE)
			ft_quicksort_a_up(all_info, \
ft_create_st_info_max(stack_info), start);
		else
			ft_quick_sort_a_d(all_info, \
ft_create_st_info_max(stack_info), start);
		ft_quick_sort_b_up(all_info, ft_crt_st_info_mid(stack_info), FALSE);
		ft_quick_sort_b_d(all_info, ft_crt_stack_info_min(stack_info), FALSE);
	}
}
