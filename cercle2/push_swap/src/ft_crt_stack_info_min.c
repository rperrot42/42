/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_stack_info_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:09:03 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:19:48 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_stack_info	ft_crt_stack_info_min(t_stack_info stack_info)
{
	if (stack_info.len <= 6)
		stack_info.len = 0;
	else if (stack_info.len <= 9)
	{
		stack_info.len -= 6;
		stack_info.max -= 6;
	}
	else
	{
		stack_info.len = stack_info.len / 3;
		stack_info.max = stack_info.min + stack_info.len - 1;
	}
	return (stack_info);
}
