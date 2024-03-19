/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:49:35 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 18:59:11 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_long(unsigned long long int nb, char *base, \
	unsigned long long int len_base)
{
	int	len;

	len = 0;
	if (nb >= len_base)
	{
		len = ft_putnbr_base_long((nb / len_base), base, len_base);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(base[nb % len_base]) < 0)
		return (-1);
	return (len + 1);
}
