/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_st_info_mid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:07:01 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_info	ft_crt_st_info_mid(t_stack_info stack_info)
{
	if (stack_info.len > 3 && stack_info.len <= 9)
	{
		if (stack_info.len <= 6)
			stack_info.len -= 3;
		else
			stack_info.len = 3;
		stack_info.max = stack_info.max - 3;
		stack_info.min = stack_info.max - stack_info.len + 1;
	}
	else if (stack_info.len > 9)
	{
		stack_info.min += stack_info.len / 3;
		stack_info.len = stack_info.len / 3 + (stack_info.len % 3 >= 1);
		stack_info.max = stack_info.min + stack_info.len - 1;
	}
	return (stack_info);
}
