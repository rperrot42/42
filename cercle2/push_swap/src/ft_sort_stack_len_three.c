/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_len_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_sort_stack_len_three(t_all_info *all_info)
{
	int		*tab;

	tab = all_info -> stack_a -> tab_stack;
	if (all_info ->stack_a -> len == 2 && (tab[0] > tab[1]))
		ft_swap(all_info, A, FALSE);
	else if (all_info ->stack_a -> len == 3)
	{
		if (tab[0] > tab[1] && tab[1] > tab[2])
		{
			ft_swap(all_info, A, FALSE);
			ft_rotate_reverse(all_info, A, FALSE);
		}
		else if (tab[0] > tab[1] && tab[2] > tab[0])
			ft_swap(all_info, A, FALSE);
		else if (tab[0] < tab[2] && tab[2] < tab[1])
		{
			ft_rotate_reverse(all_info, A, FALSE);
			ft_swap(all_info, A, FALSE);
		}
		else if (tab[0] > tab[2] && tab[0] < tab[1])
			ft_rotate_reverse(all_info, A, FALSE);
		else if (tab[0] > tab[2] && tab[1] < tab[2])
			ft_rotate(all_info, A, FALSE);
	}
}