/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:01:10 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 14:20:26 by rperrot          ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int a = -98;
	int b = 0;
	while (a++ <= 100)
		printf("%d %d\n", b += ft_is_prime(a), a);
}*/
