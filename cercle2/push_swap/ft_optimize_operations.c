/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:33:07 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:48:34 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_operation(t_operation operation_i, t_operation \
operation_i_next, t_tab_operation *tab_operation, int i);

static void	ft_delete_operation(int i, int nb_delete, \
t_tab_operation *tab_operation);

void	ft_optimize_operations(t_tab_operation *tab_operation)
{
	int			i;
	t_operation	operation_i;
	t_operation	operation_i_next;

	i = -1;
	while (++i < tab_operation -> len)
	{
		operation_i = tab_operation -> operations[i];
		operation_i_next = tab_operation -> operations[i + 1];
		if (i == tab_operation -> len - 1)
			operation_i_next = operation_i;
		make_operation(operation_i, operation_i_next, tab_operation, i);
	}
}

static void	ft_delete_operation(int i, int nb_delete, t_tab_operation \
*tab_operation)
{
	tab_operation -> len = tab_operation -> len - nb_delete;
	while (i < tab_operation -> len)
	{
		tab_operation ->operations[i] = tab_operation \
->operations[i + nb_delete];
		i++;
	}
}

static void	make_operation(t_operation operation_i, t_operation \
operation_i_next, t_tab_operation *tab_operation, int i)
{
	if ((operation_i == RA && operation_i_next == RRA) || (operation_i == \
RRA && operation_i_next == RA) || (operation_i == RB && operation_i_next == \
RRB) || (operation_i == RRB && operation_i_next == RB) || (operation_i == \
PA && operation_i_next == PB) || (operation_i == PB && operation_i_next == PA))
		ft_delete_operation(i, 2, tab_operation);
	else if ((operation_i == RRA && operation_i_next == RRB) || (\
operation_i == RRB && operation_i_next == RRA))
	{
		ft_delete_operation(i, 1, tab_operation);
		tab_operation -> operations[i] = RRR;
	}
	else if ((operation_i == RA && operation_i_next == RB) || (\
operation_i == RB && operation_i_next == RA))
	{
		ft_delete_operation(i, 1, tab_operation);
		tab_operation -> operations[i] = RR;
	}
}
