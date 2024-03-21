/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpleatoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:01:51 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:40 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static long int	ft_value_atoi(char *str, char signe);

long int	ft_simpleatoi(char *str)
{
	int		i;
	char	signe;

	i = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (2147483649);
	return (ft_value_atoi(str + i, signe));
}

static long int	ft_value_atoi(char *str, char signe)
{
	int			i;
	long int	value;

	i = 0;
	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += str[i] - 48;
		if (value > 2147483648 || (value == 2147483648 && signe == 1))
			return (2147483649);
		i++;
	}
	if (str[i])
		return (2147483649);
	return (value * signe);
}
