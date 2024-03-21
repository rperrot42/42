/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:27:41 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:17:57 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_all_info		*all_info;
	t_stack_info	stackinfo;

	all_info = malloc(sizeof(t_all_info));
	if (!all_info)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_init_start(all_info, argc - 1, argv + 1, FALSE);
	ft_init_rank(all_info->stack_a);
	if (ft_is_tried(all_info -> stack_a) == FALSE)
	{
		stackinfo.len = all_info->stack_a->len;
		stackinfo.max = stackinfo.len - 1;
		stackinfo.min = 0;
		ft_quicksort_a_up(all_info, stackinfo, TRUE);
		ft_optimize_operations(all_info->tab_operation);
		ft_print_tab_operations(all_info);
	}
	ft_free(all_info);
	return (0);
}
