/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:55:46 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/06 14:19:08 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_all_info	*all_info;

	if (argc > 1)
	{
		all_info = malloc(sizeof(t_all_info));
		if (!all_info)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		ft_init_start(all_info, argc - 1, argv + 1, FALSE);
		if (ft_checker_bonus(all_info) == TRUE)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free(all_info);
	}
}
