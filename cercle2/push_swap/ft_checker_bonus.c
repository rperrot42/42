/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:06:15 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:05:48 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation_line(char *line, t_all_info *all_info);

t_bool	ft_checker_bonus(t_all_info *all_info)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	while (line)
	{
		ft_operation_line(line, all_info);
		free(line);
		line = get_next_line(0);
	}
	if (all_info -> stack_b -> len > 0)
		return (FALSE);
	i = 0;
	while (++i < all_info -> stack_a -> len)
		if (all_info -> stack_a ->\
tab_stack[i] < all_info -> stack_a -> tab_stack[i - 1])
			return (FALSE);
	return (TRUE);
}

void	ft_operation_line(char *line, t_all_info *all_info)
{
	if (!ft_strncmp("rrr\n", line, 5))
		ft_rotate_reverse(all_info, ALL);
	else if (!ft_strncmp("rra\n", line, 5))
		ft_rotate_reverse(all_info, A);
	else if (!ft_strncmp("rrb\n", line, 5))
		ft_rotate_reverse(all_info, B);
	else if (!ft_strncmp("pa\n", line, 4))
		ft_push(all_info, A);
	else if (!ft_strncmp("pb\n", line, 4))
		ft_push(all_info, B);
	else if (!ft_strncmp("ra\n", line, 4))
		ft_rotate(all_info, A);
	else if (!ft_strncmp("rb\n", line, 4))
		ft_rotate(all_info, B);
	else if (!ft_strncmp("rr\n", line, 4))
		ft_rotate(all_info, ALL);
	else if (!ft_strncmp("sa\n", line, 4))
		ft_swap(all_info, A);
	else if (!ft_strncmp("sb\n", line, 4))
		ft_swap(all_info, B);
	else if (!ft_strncmp("ss\n", line, 4))
		ft_swap(all_info, ALL);
	else
		ft_free_error(all_info);
}
