/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:06:53 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/18 20:22:53 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int b(char *a)
{
	if (a[0] == 'e')
		return (1);
	return (0);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	argv[argc - 1] = 0;
	printf("%d\n",ft_any(argv + 1,&b));
}*/
