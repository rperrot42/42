/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/19 14:50:34 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

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

void	ft_sort_string_tab(char **tab)
{
	char	*echange;
	int		i;
	int		j;
	int		index_min;

	i = 0;
	while (tab[i])
	{
		index_min = i;
		j = i;
		while (tab[j])
		{
			if (compare_str(tab[index_min], tab[j]) > 0)
				index_min = j;
			j++;
		}
		echange = tab[i];
		tab[i] = tab[index_min];
		tab[index_min] = echange;
		i++;
	}
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	argv[argc - 1] = 0; 
	ft_sort_char(argv+1);
	int i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}*/
