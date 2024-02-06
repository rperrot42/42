/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:32:09 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/24 16:04:04 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_free(char *last, char *return_value)
{
	if (last)
		free(last);
	if (return_value)
		free(return_value);
	return (NULL);
}

void	ft_change_buffer(char *last, char *buffer)
{
	size_t	i;
	size_t	len_buffer;
	size_t	j;

	if (!last)
	{
		buffer[0] = 0;
		return ;
	}
	i = 0;
	while (last[i] && last[i] != '\n')
		i++;
	i++;
	len_buffer = ft_strlen(last) - i;
	if ((int)len_buffer <= 0)
	{
		*buffer = 0;
		free(last);
		return ;
	}
	j = -1;
	while (++j < len_buffer)
		buffer[j] = last[i + j];
	buffer[j] = 0;
	free(last);
}

char	*ft_create_line(char *last)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (!last)
		return (ft_free(last, NULL));
	len = ft_findnewline(last);
	if (len == 0)
		return (ft_free(last, NULL));
	line = malloc (len + 1);
	if (!line)
		return (ft_free(last, line));
	i = -1;
	while (++i < len)
		line[i] = last[i];
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*last;
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*return_value;
	int			r;

	last = NULL;
	return_value = NULL;
	last = ft_strjoin(last, buffer[fd], 0);
	r = 1;
	while (1)
	{
		if (r == 0 || ft_find_jump(last) != 0)
		{
			return_value = ft_create_line(last);
			if (!return_value)
				return (NULL);
			ft_change_buffer(last, buffer[fd]);
			return (return_value);
		}
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r < 0)
			return (ft_free(last, return_value));
		if (r)
			last = ft_strjoin(last, buffer[fd], r);
	}
}
