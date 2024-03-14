/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_distance_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:27:43 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/14 17:27:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

float	**init_distance_pixel(void)
{
	int		i;
	float	**distance_pixel;

	distance_pixel = malloc(sizeof(float *) * HEIGHT);
	if (!distance_pixel)
		return (NULL);
	i = -1;
	while (++i < HEIGHT)
	{
		distance_pixel[i] = malloc(sizeof(float) * WIDTH);
		if (!distance_pixel[i])
			return (free_distance_pixel(distance_pixel, i), NULL);
	}
	return (distance_pixel);
}

void	free_distance_pixel(float **distance_pixel, int size)
{
	int	i;

	if (size == -1)
		size = HEIGHT;
	i = -1;
	while (++i < size)
		free(distance_pixel[i]);
	free(distance_pixel);
}

void	put_distance_pixel_float_max(float **distance_pixel)
{
	int	i;
	int j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			distance_pixel[i][j] = FLT_MAX;
	}
}