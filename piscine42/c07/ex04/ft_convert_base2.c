/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 20:30:47 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	putnbr_base_rec(int nbr, char *base, int lenght_base, char *back_base);
int		char_is_str(char *str, char c, int i);
int		check_base(char *base, int *lenght_base);
char	*ft_putnbr_base(int nbr, char *base);
void	modif_value(long int *value, int positive, int lenght_base, int i_base);

void	init_variable(int *positive, long int *value, int *is_in_base)
{
	*positive = 1;
	*is_in_base = 1;
	*value = 0;
}

long int	value_atoi(char *str, int i, char *base, int lenght_base)
{
	int			is_in_base;
	int			i_base;
	long int	value;
	int			positive;

	init_variable(&positive, &value, &is_in_base);
	if (str[i - 1] == '-')
		positive = 0;
	while (is_in_base && str[i])
	{
		i_base = 0;
		while (i_base < lenght_base && str[i] != base[i_base])
			i_base++;
		if (i_base == lenght_base)
			is_in_base = 0;
		else
		{
			modif_value(&value, positive, lenght_base, i_base);
			i++;
			if (value > 2147483647 || value < -2147483648)
				return (2147483649);
		}
	}
	return (value);
}

int	base_valid(char *base, int *lenght_base)
{
	*lenght_base = 0;
	while (base[*lenght_base])
	{
		if (base[*lenght_base] == '+' || base[*lenght_base] == '-')
			return (0);
		if (base[*lenght_base] >= 7 && base[*lenght_base] <= 13)
			return (0);
		if (base[*lenght_base] == ' ')
			return (0);
		if (char_is_str(base, base[*lenght_base], *lenght_base + 1) == 0)
			return (0);
		*lenght_base = *lenght_base + 1;
	}
	if (*lenght_base <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base, int *correct)
{
	int			i;
	long int	value;
	int			signe;
	int			lenght_base;

	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	if (i > 0)
		str[i - 1] = '+';
	if (!base_valid(base, &lenght_base))
		*correct = 0;
	if (signe == -1)
		str[i - 1] = '-';
	value = value_atoi(str, i, base, lenght_base);
	if (value > 2147483648)
		*correct = 0;
	return ((int)value);
}

char	*ft_convert_base(char *nbr, char *basefrom, char *base_to)
{
	int		value;
	int		correct;

	correct = 1;
	value = ft_atoi_base(nbr, basefrom, &correct);
	if (!correct)
		return (NULL);
	return (ft_putnbr_base(value, base_to));
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	char *a = ft_convert_base(argv[1],argv[2], argv[3]);
	printf("%s",a);
	free(a);
}*/
