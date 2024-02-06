/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:04:07 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/16 21:22:23 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	borne_inf;
	int	borne_sup;
	int	borne_avg;

	if (nb <= 0)
		return (0);
	borne_inf = 1;
	borne_sup = 46341;
	while (borne_inf != borne_sup - 1)
	{
		borne_avg = (borne_inf + borne_sup) / 2;
		if (borne_avg * borne_avg > nb)
			borne_sup = borne_avg;
		else
			borne_inf = borne_avg;
	}
	return (borne_inf);
}

int	ft_is_prime(int nb)
{
	int	sqrt;
	int	i;
	int	nb_divis;

	nb_divis = 0;
	i = 1;
	sqrt = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	while (i <= (sqrt))
	{
		if (nb % i == 0)
		{
			nb_divis += 2;
			if (nb_divis > 2)
				return (0);
			if (i > 2)
				i++;
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 2)
		return (2);
	i = 0;
	while (!ft_is_prime(nb + i))
	{
		if (i + nb % 2 == 0)
			i++;
		else
			i += 2;
	}
	return (nb + i);
}
/*
#include <stdio.h>
int main()
{
	int a = 2000001678;
	printf("%d", ft_find_next_prime(a));
}*/
