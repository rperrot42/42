/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:24:30 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 21:31:32 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	nb_other_0;

	i = 0;
	nb_other_0 = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			nb_other_0++;
		i++;
	}
	return (nb_other_0);
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
