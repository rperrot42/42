/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:17:38 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 16:47:30 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_combn_rec(char *all_n, int n, int n_start)
{
	int	i;

	if (n == 0)
	{
		i = n_start;
		while (i >= 1)
		{
			write(1, &all_n[i], 1);
			i --;
		}
		if (all_n[n_start] != '9' - n_start + 1)
			write(1, ", ", 2);
	}
	else
	{
		while (all_n[n] <= '9' - n + 1)
		{
			all_n[n - 1] = all_n[n] + 1;
			ft_print_combn_rec(&all_n[0], n - 1, n_start);
			all_n[n]++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	all_n[10];

	all_n[n] = '0';
	ft_print_combn_rec(&all_n[0], n, n);
}
