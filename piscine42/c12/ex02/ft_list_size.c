/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:36:37 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 22:07:32 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdio.h>
int	ft_list_size(t_list *begin_list)
{
	int len;
	struct s_list *list_next;
	
	list_next = begin_list;
	len = 0;

	while (list_next)
	{
		printf("%d len\n",len);
		list_next = list_next -> next;
		len++;
	}
	return (len);
}

int main ()
{
	struct s_list *a;
	struct s_list *b;
	struct s_list *c;
	a -> data = 1;
	a -> next = b;
	b -> data = 1;
	b -> next = c;
	c -> data = 2;
	c -> next = 0;
	int d = ft_list_size(a);
	printf("%d", d);
}
