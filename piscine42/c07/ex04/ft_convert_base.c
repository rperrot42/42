/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:49:35 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 16:39:20 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

long int	value_atoi(char *str, int i, char *base, int lenght_base);
int			base_valid(char *base, int *lenght_base);
int			ft_atoi_base(char *str, char *base, int *correct);
char		*ft_convert_base(char *nbr, char *basefrom, char *base_to);

void	modif_value(long int *value, int positive, int lenght_base, int i_base)
{
	if (positive)
		*value = *value * lenght_base + i_base;
	else
		*value = *value * lenght_base - i_base;
}

char	*putnbr_base_rec(int nbr, char *base, int lenght_base, char *back_base)
{
	int	i;

	i = 0;
	if (nbr >= lenght_base || nbr <= -lenght_base)
		putnbr_base_rec(nbr / lenght_base, base, lenght_base, back_base);
	while (back_base[i])
		i++;
	if (nbr >= 0)
		back_base[i] = base[nbr % lenght_base];
	else
		back_base[i] = base[nbr % lenght_base * -1];
	return (back_base);
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

int	check_base(char *base, int *lenght_base)
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

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*backbase;
	int		lenght_base;
	int		len_backbase;
	int		nbr_copie;

	nbr_copie = nbr;
	len_backbase = 0;
	if (check_base(base, &lenght_base) == 0)
		return (NULL);
	while (nbr >= lenght_base || nbr <= -lenght_base)
	{
		nbr /= lenght_base;
		len_backbase++;
	}
	if (nbr < 0)
		len_backbase++;
	backbase = malloc(sizeof(char) * len_backbase + 2);
	nbr = -1;
	while (++nbr < len_backbase + 2)
		backbase[nbr] = 0;
	if (backbase == NULL)
		return (NULL);
	if (nbr_copie < 0)
		backbase[0] = '-';
	return (putnbr_base_rec(nbr_copie, base, lenght_base, backbase));
}
