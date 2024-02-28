/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:04:57 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 18:59:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	int	signe;

	signe = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		signe = 1;
		n = -n;
		if (ft_putchar('-') < 0)
			return (0);
	}
	if (n >= 10)
		len = ft_putnbr(n / 10);
	if (len == -1)
		return (-1);
	if (ft_putchar(n % 10 + '0') < 0)
		return (-1);
	if (signe)
		len++;
	return (len + 1);
}
