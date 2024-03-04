/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:06:49 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/01 19:06:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

static unsigned	int	ft_atoi_base_avanc(char **str, char *base);

t_point_3d	create_point3d(char **line)
{
	t_point_3d	point_3d;

	if (**line == ' ')
		*line = *line + 1;
	point_3d.z = ft_atoi_base_avanc(line, BASE_10);
	if (**line == ',')
	{
		*line = *line + 3;
		point_3d.color = ft_atoi_base_avanc(line,  BASE_HEXA);
	}
	else
		point_3d.color = 0;
	if (**line)
		*line = *line + 1;
	return (point_3d);
}

static unsigned int	ft_atoi_base_avanc(char **str,  char *base)
{
	unsigned int	value;
	int				is_in_base;
	int				i_base;
	int 			length_base;

	value = 0;
	length_base = ft_strlen(base);
	is_in_base = 1;
	while (is_in_base && **str)
	{
		i_base = 0;
		while (i_base < length_base && **str != base[i_base])
			i_base++;
		if (i_base == length_base)
			is_in_base = 0;
		else
		{
			value *= length_base;
			value += i_base;
			*str = *str + 1;
		}
	}
	return (value);
}
