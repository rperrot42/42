/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:36:50 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/13 20:32:38 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (ft_recursive_power(nb, power - 1) * nb);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	printf("%d", ft_recursive_power(atoi(argv[1]),atoi(argv[2])));
}*/
