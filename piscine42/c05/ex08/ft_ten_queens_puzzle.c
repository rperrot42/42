/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:05:54 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/18 14:01:30 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_write_tab(char *tab)
{
	char	c;
	int		i;

	i = 0;
	while (i <= 9)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_possible(char *tab, int size)
{
	int	i;
	int	value;

	value = tab[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		if (tab[i] == value)
			return (0);
		if (tab[i] == value + (size - i - 1) || tab[i] == value - (size - i -1))
			return (0);
		i--;
	}
	return (1);
}

int	ft_get_next_move(char *tab, int row)
{
	int	i;
	int	nb_possibility;

	if (row == 10)
	{
		ft_write_tab(tab);
		return (1);
	}
	nb_possibility = 0;
	i = 0;
	while (i < 10)
	{
		tab[row] = i;
		if (ft_is_possible(tab, row + 1))
		{
			nb_possibility += ft_get_next_move(tab, row + 1);
		}
		i++;
	}
	return (nb_possibility);
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[10];
	int		nb_queens_puzzle;

	nb_queens_puzzle = ft_get_next_move(tab, 0);
	return (nb_queens_puzzle);
}
/*
#include <stdio.h>
int main()
{
	int a = ft_ten_queens_puzzle();
	printf("%d",a);
}*/
