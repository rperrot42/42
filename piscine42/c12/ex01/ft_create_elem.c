/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:44:31 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/20 12:55:34 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	struct s_list	*list;

	list = malloc(sizeof(t_list));
	list -> data = data;
	list -> next = NULL;
	return (list);
}
/*
#include <stdio.h>
int main()
{
	struct s_list *a = ft_create_elem("bonjour");
	printf("%s %p\n", a->data, a->next);
}*/
