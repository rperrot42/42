/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:37:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/17 21:28:44 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	name_is_valide(char	*name);

int	main(int argc, char **argv)
{
	t_all_info	*all_info;

	if (argc == 2)
	{
		name_is_valide(argv[1]);
		all_info = init_all_info(argv[1]);
		if (!all_info)
			exit(1);
		transforme_matrix_3d_in2d(all_info->all_matrix, all_info->display_info);
		display_all(all_info);
		mlx_hook(all_info->vars->win, 4, 1L << 2, button_press, all_info);
		mlx_hook(all_info->vars->win, 5, 1L << 3, button_release, \
		all_info->info_event);
		mlx_hook(all_info->vars->win, 6, 1L << 6, motion_notify, all_info);
		mlx_hook(all_info->vars->win, 17, 1L << 0, free_all_info_sucess, \
		all_info);
		mlx_hook(all_info->vars->win, 2, 1L << 0, keycode_move, all_info);
		mlx_loop_hook(all_info->vars->mlx, display_all, all_info);
		mlx_loop(all_info->vars->mlx);
	}
	return (0);
}

static void	name_is_valide(char	*name)
{
	int	len_str;
	int	len_file_ext_fdf;

	len_str = ft_strlen(name);
	len_file_ext_fdf = ft_strlen(FILE_EXTENSION_FDF);
	if (len_str < len_file_ext_fdf)
	{
		ft_putstr_fd(ERROR_EXT_NO_VALIDE, 2);
		exit(1);
	}
	if (ft_strncmp(name + len_str - len_file_ext_fdf, \
	FILE_EXTENSION_FDF, len_file_ext_fdf))
	{
		ft_putstr_fd(ERROR_EXT_NO_VALIDE, 2);
		exit(1);
	}
}
