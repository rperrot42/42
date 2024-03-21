/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_operation_in_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:47:29 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:19:23 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_add_operation_in_tab(t_tab_operation *tab_operation, \
t_operation operation)
{
	int	len;

	len = tab_operation -> len;
	tab_operation -> operations[len] = operation;
	tab_operation -> len += 1;
}
