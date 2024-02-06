/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 11:53:40 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	value_atoi(char *str, int i, char *base, int lenght_base)
{
	int	value;
	int	is_in_base;
	int	i_base;

	value = 0;
	is_in_base = 1;
	while (is_in_base && str[i])
	{
		i_base = 0;
		while (i_base < lenght_base && str[i] != base[i_base])
			i_base++;
		if (i_base == lenght_base)
			is_in_base = 0;
		else
		{
			value *= lenght_base;
			value += i_base;
			i++;
		}
	}
	return (value);
}

int	char_is_str(char *str, char c, int i)
{
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	base_valid(char *base, int *lenght_base)
{
	*lenght_base = 0;
	while (base[*lenght_base])
	{
		if (base[*lenght_base] == '+' || base[*lenght_base] == '-')
			return (0);
		if (base[*lenght_base] == 32 || \
				(base[*lenght_base] >= 7 && base[*lenght_base] <= 13))
			return (0);
		if (char_is_str(base, base[*lenght_base], *lenght_base + 1) == 0)
			return (0);
		*lenght_base = *lenght_base + 1;
	}
	if (*lenght_base <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	value;
	int	signe;
	int	lenght_base;

	signe = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	if (!base_valid(base, &lenght_base))
		return (0);
	value = value_atoi(str, i, base, lenght_base);
	if (signe % 2)
		value *= -1;
	return (value);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	printf("%d",ft_atoi_base(argv[1],argv[2]));
}*/
