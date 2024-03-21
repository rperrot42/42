/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tried.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:45:18 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 19:45:18 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_bool	ft_is_tried(t_tab_stack *stack_a)
{
	int	i;

	i = 0;
	while (++i < stack_a -> len)
		if (stack_a ->tab_stack[i] < stack_a -> tab_stack[i - 1])
			return (FALSE);
	return (TRUE);
}
