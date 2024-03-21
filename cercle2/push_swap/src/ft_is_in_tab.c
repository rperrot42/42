/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:19:09 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:20:05 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_bool	ft_is_in_tab(t_tab_stack *stack_a, int value)
{
	int		i;
	t_bool	value_is_in_tab;
	int		len;
	int		*tab_a;

	len = stack_a -> len;
	tab_a = stack_a -> tab_stack;
	value_is_in_tab = FALSE;
	i = -1;
	while (++i < len)
		if (tab_a[i] == value)
			value_is_in_tab = TRUE;
	return (value_is_in_tab);
}
