/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:06:15 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:19:30 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_operation_line(char *line, t_all_info *all_info);

t_bool	ft_checker_bonus(t_all_info *all_info)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_operation_line(line, all_info);
		free(line);
		line = get_next_line(0);
	}
	if (all_info -> stack_b -> len > 0)
		return (FALSE);
	return (ft_is_tried(all_info -> stack_a));
}

void	ft_operation_line(char *line, t_all_info *all_info)
{
	if (!ft_strncmp("rrr\n", line, 5))
		return (ft_rotate_reverse(all_info, ALL, TRUE));
	else if (!ft_strncmp("rra\n", line, 5))
		return (ft_rotate_reverse(all_info, A, TRUE));
	else if (!ft_strncmp("rrb\n", line, 5))
		return (ft_rotate_reverse(all_info, B, TRUE));
	else if (!ft_strncmp("pa\n", line, 4))
		return (ft_push(all_info, A, TRUE));
	else if (!ft_strncmp("pb\n", line, 4))
		return (ft_push(all_info, B, TRUE));
	else if (!ft_strncmp("ra\n", line, 4))
		return (ft_rotate(all_info, A, TRUE));
	else if (!ft_strncmp("rb\n", line, 4))
		return (ft_rotate(all_info, B, TRUE));
	else if (!ft_strncmp("rr\n", line, 4))
		return (ft_rotate(all_info, ALL, TRUE));
	else if (!ft_strncmp("sa\n", line, 4))
		return (ft_swap(all_info, A, TRUE));
	else if (!ft_strncmp("sb\n", line, 4))
		return (ft_swap(all_info, B, TRUE));
	else if (!ft_strncmp("ss\n", line, 4))
		return (ft_swap(all_info, ALL, TRUE));
	free(line);
	ft_free_error(all_info);
}
