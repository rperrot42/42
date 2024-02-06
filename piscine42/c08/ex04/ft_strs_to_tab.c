/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:33:42 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 16:56:42 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str);

struct s_stock_str	create_struct(char *str)
{
	struct s_stock_str	crt_struct;
	int					strlen;
	int					i;
	char				*str_copy;

	strlen = str_len(str);
	crt_struct.size = strlen;
	crt_struct.str = str;
	str_copy = malloc(sizeof(char) * (strlen + 1));
	i = 0;
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = 0;
	crt_struct.copy = str_copy;
	return (crt_struct);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*all_struct;

	i = 0;
	all_struct = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (all_struct == NULL)
		return (NULL);
	while (i < ac)
	{
		all_struct[i] = create_struct(av[i]);
		i++;
	}
	all_struct[i].size = 0;
	all_struct[i].str = 0;
	all_struct[i].copy = 0;
	return (all_struct);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	struct s_stock_str *a = ft_strs_to_tab(argc - 1, argv + 1);
	int i = 0;
	while (a[i].str != 0)
	{
		printf("%d %s %s \n",a[i].size, a[i].str, a[i].copy);
		i++;

	}
	free(a);
}*/
