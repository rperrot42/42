/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:14:03 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 19:59:53 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = 0;
	while (i < (size / 2))
	{
		c = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = c;
		i++;
	}	
}
