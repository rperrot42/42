/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:02:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 20:25:46 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	index_min;
	int	echange;

	i = 0;
	while (i < size)
	{
		j = i;
		index_min = i;
		while (j < size)
		{
			if (tab[index_min] > tab[j])
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
int main(void)
{
	int a[]={5,2,4,1,3};
	ft_sort_int_tab(&a[0],5);
	printf("%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
}*/
