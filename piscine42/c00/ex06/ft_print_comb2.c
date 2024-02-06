/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:08:38 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/05 19:41:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	number1;
	int	number2;

	number1 = 0;
	while (number1 <= 98)
	{
		number2 = number1 + 1;
		while (number2 <= 99)
		{
			ft_putchar(number1 / 10 + '0');
			ft_putchar(number1 % 10 + '0');
			write(1, " ", 1);
			ft_putchar(number2 / 10 + '0');
			ft_putchar(number2 % 10 + '0');
			if (number1 != 98)
				write(1, ", ", 2);
			number2 ++;
		}
		number1 ++;
	}	
}
