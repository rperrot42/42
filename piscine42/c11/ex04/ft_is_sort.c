/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:32:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 15:31:33 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			j++;
		i++;
	}
	if (j == i)
		return (1);
	i = 0;
	j = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			j++;
		i++;
	}
	if (j == i)
		return (1);
	return (0);
}

/*#include <stdio.h>

int b (int a, int b)
{
	return (a - b);
}
int main ()
{
	int tab[5] = {5,4,3,2,1};
	printf("%d\n",ft_is_sort(tab, 5, &b));
}*/
