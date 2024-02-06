/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:36:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 19:05:34 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_len_three(t_all_info *all_info, int *tab);

static void	ft_sort_desc_len_three(t_all_info *all_info);

void	ft_sort_three_nombers(t_all_info *all_info, int len)
{
	int	*tab;

	tab = all_info -> stack_a -> tab_stack;
	if (len == 2 && tab[1] < tab[0])
		ft_swap(all_info, A);
	else if (len == 3)
		ft_sort_len_three(all_info, tab);
}

static void	ft_sort_len_three(t_all_info *all_info, int *tab)
{
	if (tab[0] > tab[1] && tab[1] > tab[2])
		ft_sort_desc_len_three(all_info);
	else if (tab[0] > tab[1] && tab[2] > tab[0])
		ft_swap(all_info, A);
	else if (tab[0] < tab[2] && tab[2] < tab[1])
	{
		ft_rotate(all_info, A);
		ft_swap(all_info, A);
		ft_rotate_reverse(all_info, A);
	}
	else if (tab [0] > tab[2] && tab[0] < tab[1])
	{
		ft_rotate(all_info, A);
		ft_swap(all_info, A);
		ft_rotate_reverse(all_info, A);
		ft_swap(all_info, A);
	}
	else if (tab[0] > tab[2] && tab[1] < tab[2])
	{
		ft_swap(all_info, A);
		ft_rotate(all_info, A);
		ft_swap(all_info, A);
		ft_rotate_reverse(all_info, A);
	}
}

static void	ft_sort_desc_len_three(t_all_info *all_info)
{
	ft_swap(all_info, A);
	ft_rotate(all_info, A);
	ft_swap(all_info, A);
	ft_rotate_reverse(all_info, A);
	ft_swap(all_info, A);
}
