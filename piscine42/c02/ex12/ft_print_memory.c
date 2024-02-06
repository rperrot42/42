/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:28:02 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 20:22:56 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_characters(unsigned char *str, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	write(1, " ", 1);
	while (i + j < size && j < 16)
	{
		if (str[i + j] <= 31 || str[i + j] >= 127)
			write(1, ".", 1);
		else
			ft_putchar(str[i + j]);
		j++;
	}
}

void	print_adresse_memory(unsigned char *adresse_memory, char *base)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_putchar(base[adresse_memory[i] / 16]);
		ft_putchar(base[adresse_memory[i] % 16]);
		i--;
	}
	write(1, ":", 1);
}

void	print_hexa(unsigned char *addr, int i, int size, char *hexa_char)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (j % 2 == 0)
			write(1, " ", 1);
		if (i + j < size)
		{
			ft_putchar(hexa_char[addr[i + j] / 16]);
			ft_putchar(hexa_char[addr[i + j] % 16]);
		}
		else
			write(1, "  ", 2);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*char_addr_p;
	unsigned char	*char_addr;
	char			*hexa_char;
	unsigned int	i;

	hexa_char = "0123456789abcdef";
	char_addr = (unsigned char *)addr;
	char_addr_p = (unsigned char *)&addr;
	i = 0;
	while (i < size)
	{
		print_adresse_memory(char_addr_p, hexa_char);
		print_hexa(char_addr, i, size, hexa_char);
		print_characters(char_addr, i, size);
		*char_addr_p += 16;
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
/*
int main()
{
	char a[30] = "coucou tu vas bien \n ";
	a[2] = 215;
	ft_print_memory(a, 30);
	printf("%p\n", a);
}*/
