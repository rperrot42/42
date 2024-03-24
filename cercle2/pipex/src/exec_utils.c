/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:40:37 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/24 17:40:37 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_exec_info(t_exec_info *exec_info)
{
	exec_info->path_test = NULL;
	exec_info->arg = NULL;
	exec_info->elmnt_path = NULL;
}
