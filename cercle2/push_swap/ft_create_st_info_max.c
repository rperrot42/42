/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_st_info_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:06:03 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/20 19:22:51 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_info	ft_create_st_info_max(t_stack_info stack_info)
{
	if (stack_info.len <= 9 && stack_info.len > 3)
	{
		stack_info.len = 3;
		stack_info.min = stack_info.max - 2;
	}
	else
	{
		stack_info.len = stack_info.len / 3 + (stack_info.len % 3 == 2);
		stack_info.min = stack_info.max - stack_info.len + 1;
	}
	return (stack_info);
}
