/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:04 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/10 16:58:14 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

void	init_info_event(t_info_event *info_event)
{
	info_event->left_click = FALSE;
	info_event->right_click = FALSE;
}

int	button_press(int keycode, int x, int y, t_all_info *all_info)
{
	if (keycode == LEFT_CLICK)
	{
		all_info->info_event->left_click = TRUE;
		all_info->info_event->position_x = x;
		all_info->info_event->position_y = y;
	}
	else if (keycode == RIGHT_CLICK)
	{
		all_info->info_event->right_click = TRUE;
		all_info->info_event->position_x = x;
		all_info->info_event->position_y = y;
	}
	else if (keycode == SCROLING_UP)
		return (change_value_min_z(all_info->display_info, UP));
	else if (keycode == SCROLING_DOWN)
		return (change_value_min_z(all_info->display_info, DOWN));
	return (0);
}


int	button_release(int keycode, int x, int y, t_info_event *info_event)
{
	if (keycode == LEFT_CLICK)
	{
		info_event->left_click = FALSE;
		info_event->position_x = x;
		info_event->position_y = y;
	}
	else if (keycode == RIGHT_CLICK)
	{
		info_event->right_click = FALSE;
		info_event->position_x = x;
		info_event->position_y = y;
	}
	return (0);
}

int	motion_notify(int x, int y, t_all_info *all_info)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
	{
		all_info->info_event->left_click = FALSE;
		all_info->info_event->right_click = FALSE;
	}
	if (all_info->info_event->left_click == TRUE)
	{
		all_info->display_info->move_x += x - all_info->info_event->position_x;
		all_info->display_info->move_y += y - all_info->info_event->position_y;
		all_info->info_event->position_x = x;
		all_info->info_event->position_y = y;
		return  (0);
	}
	if (all_info->info_event->right_click == TRUE)
	{
		create_vector_multiplicator(all_info->display_info->rotation_vector, y - all_info->info_event->position_y, all_info->info_event->position_x - x);
		all_info->info_event->position_x = x;
		all_info->info_event->position_y = y;
		return  (0);
	}
	return (0);
}