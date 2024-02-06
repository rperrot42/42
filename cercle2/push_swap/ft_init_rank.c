/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:57:33 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/19 16:30:22 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_valeur_min(t_tab_stack *stack_a);

void	ft_init_rank(t_tab_stack *stack_a)
{
	int	len;
	int	i;
	int	j;
	int	indice_min;
	int	valeur_min;

	i = -1;
	len = stack_a -> len;
	while (++i < len)
	{
		j = -1;
		valeur_min = INT32_MAX;
		while (++j < len)
		{
			if (stack_a -> tab_stack[j] >= INT32_MIN + i && \
stack_a -> tab_stack[j] < valeur_min)
			{
				valeur_min = stack_a -> tab_stack[j];
				indice_min = j;
			}
		}
		stack_a -> tab_stack[indice_min] = INT32_MIN + i;
	}
	ft_add_valeur_min(stack_a);
}

static void	ft_add_valeur_min(t_tab_stack *stack_a)
{
	int	len;
	int	i;
	int	*tab;

	tab = stack_a -> tab_stack;
	i = -1;
	len = stack_a -> len;
	while (++i < len)
		tab[i] -= INT32_MIN;
}
