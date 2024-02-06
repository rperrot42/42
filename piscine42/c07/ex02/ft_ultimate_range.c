/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:06:25 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 14:59:48 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*#include <stdio.h>
int main(int argc, char **argv)
{
	int min = 2;
	int max = 25;
	int *tab;
       	int b =ft_ultimate_range(&tab, min, max);
	int i = 0;
        while (i < max - min)
        {
                printf("%d\n",tab[i]);
                i++;
        }
	printf("%d", b);
}*/
