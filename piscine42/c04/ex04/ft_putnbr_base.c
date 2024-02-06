/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:49:35 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 11:46:15 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_rec(int nbr, char *base, int lenght_base)
{
	if (nbr >= lenght_base || nbr <= -lenght_base)
		ft_putnbr_base_rec(nbr / lenght_base, base, lenght_base);
	if (nbr >= 0)
		ft_putchar(base[nbr % lenght_base]);
	else
		ft_putchar(base[nbr % lenght_base * -1]);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenght_base;

	lenght_base = 0;
	while (base[lenght_base])
	{
		if (base[lenght_base] == '+' || base[lenght_base] == '-')
			return ;
		if (char_is_str(base, base[lenght_base], lenght_base + 1) == 0)
			return ;
		lenght_base ++;
	}
	if (lenght_base <= 1)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	ft_putnbr_base_rec(nbr, base, lenght_base);
}
/*
#include <stdlib.h>
int main (int argc, char **argv)
{
	ft_putnbr_base(atoi(argv[1]), argv[2]);
}*/
