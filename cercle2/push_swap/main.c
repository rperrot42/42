/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:27:41 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 19:03:56 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stackinfo.len = all_info ->stack_a ->len;
	stackinfo.max = stackinfo.len - 1;
	stackinfo.min = 0;
	ft_quicksort_a_up(all_info, stackinfo, TRUE);
	ft_optimize_operations(all_info->tab_operation);
	ft_print_tab_operations(all_info);
	ft_free(all_info);
	return (0);
}
