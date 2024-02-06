/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 15:16:47 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}*/

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
		while (cmp(tab[j], tab[j - 1]) < 0 && j > 0)
		{
			echange = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = echange;
			j--;
		}
		i++;
	}
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	argv[argc - 1] = 0; 
	ft_advanced_sort_string_tab(argv+1, &ft_strcmp);
	int i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}*/
