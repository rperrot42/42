/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:39:55 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 21:33:40 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	struct s_list	**newlist;
	struct s_list	*copy;

	copy = *begin_list;
	newlist = begin_list;
	*newlist	= ft_create_elem(data);
	(*newlist) -> next = copy;
}
/*
#include <stdio.h>
int main()
{
	void *inta = 1;
	void *intb = 2;
	struct s_list *a = ft_create_elem(intb);
	ft_list_push_front(&a, inta);
	printf("%d %d", a->data , a->next->data);
}*/
