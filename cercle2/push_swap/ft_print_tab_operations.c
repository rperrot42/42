/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:55:19 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:42:41 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print_operation(t_operation operation);

void	ft_print_tab_operations(t_all_info *all_info)
{
	int			i;
	int			len;
	t_operation	*operations;

	len = all_info -> tab_operation->len;
	operations = all_info -> tab_operation->operations;
	i = -1;
	while (++i < len)
	{
		if (ft_print_operation(operations[i]) < 0)
			ft_free_error(all_info);
	}
}

static int	ft_print_operation(t_operation operation)
{
	if (operation == SA)
		return (ft_printf("sa\n"));
	else if (operation == SB)
		return (ft_printf("sb\n"));
	else if (operation == SS)
		return (ft_printf("ss\n"));
	else if (operation == PA)
		return (ft_printf("pa\n"));
	else if (operation == PB)
		return (ft_printf("pb\n"));
	else if (operation == RA)
		return (ft_printf("ra\n"));
	else if (operation == RB)
		return (ft_printf("rb\n"));
	else if (operation == RR)
		return (ft_printf("rr\n"));
	else if (operation == RRA)
		return (ft_printf("rra\n"));
	else if (operation == RRB)
		return (ft_printf("rrb\n"));
	else
		return (ft_printf("rrr\n"));
}
