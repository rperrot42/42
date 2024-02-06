/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/16 20:44:47 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	compare_str(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_print_params(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_sort_char(char **argv, int size)
{
	char	*echange;
	int		i;
	int		j;
	int		index_min;

	i = 1;
	while (i < size)
	{
		index_min = i;
		j = i;
		while (j < size)
		{
			if (compare_str(argv[index_min], argv[j]) >= 0)
				index_min = j;
			j++;
		}
		echange = argv[i];
		argv[i] = argv[index_min];
		argv[index_min] = echange;
		i++;
	}
}

int	main(int argc, char **argv)
{
	ft_sort_char(argv, argc);
	ft_print_params(argv, argc);
	return (0);
}
