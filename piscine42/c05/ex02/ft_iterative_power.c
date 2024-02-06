/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:38:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/13 20:30:45 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	power_value;

	power_value = 1;
	i = 0;
	if (power < 0)
		return (0);
	while (i < power)
	{
		power_value *= nb;
		i ++;
	}
	return (power_value);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
        printf("%d", ft_iterative_power(atoi(argv[1]),atoi(argv[2])));
}*/
