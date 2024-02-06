/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:45:10 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/10 10:33:39 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	modif_char(unsigned char c)
{
	char	*bas_hex;

	write(1, "\\", 1);
	bas_hex = "0123456789abcdef";
	ft_putchar(bas_hex[c / 16]);
	ft_putchar(bas_hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 31) || (str[i] >= 127))
			modif_char((unsigned char) str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
