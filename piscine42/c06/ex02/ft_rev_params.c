/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/11 18:01:53 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_params(char **argv, int argc)
{
	int	i;
	int	j;

	i = argc -1;
	while (i)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	ft_rev_params(argv, argc);
	return (0);
}
