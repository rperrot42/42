/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:04:20 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 20:45:41 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_comb(void)
{
	char	number1;
	char	number2;
	char	number3;

	number1 = '0';
	while (number1 <= '7')
	{
		number2 = number1 + 1;
		while (number2 <= '8')
		{
			number3 = number2 + 1;
			while (number3 <= '9')
			{
				write(1, &number1, 1);
				write(1, &number2, 1);
				write(1, &number3, 1);
				if (number1 != '7')
					write(1, ", ", 2);
				number3 ++;
			}
			number2++;
		}
		number1 ++;
	}
}
/*
int main (void)
{
	ft_print_comb();
}*/
