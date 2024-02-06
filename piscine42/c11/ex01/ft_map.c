/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:58:09 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/18 20:00:48 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*back_tab;
	int	i;

	back_tab = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		back_tab[i] = f(tab[i]);
		i++;
	}
	return (back_tab);
}
/*
int f(int b)
{
	return (b * 2);
}
#include <stdio.h>
int main(void)
{
	int b[] = {1, 2, 3, 4 ,5};
	int *a = ft_map(b, 5 ,&f);
	int i = 0;
	while (i < 5)
	{
		printf("%d\n",a[i]);
		i++;
	}
}*/
