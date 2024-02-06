/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:06:25 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/14 13:02:19 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (0);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int *tab = ft_range(min, max);
	int i = 0;
        while (i < max- min)
        {
                printf("%d\n",tab[i]);
                i++;
        }
	

}*/
