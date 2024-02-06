/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:30:36 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/14 12:59:36 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		i;
	int		lenght_src;

	lenght_src = 0;
	i = 0;
	while (src[lenght_src])
		lenght_src++;
	new_src = malloc(sizeof(char) * lenght_src + 1);
	if (new_src == NULL)
		return (NULL);
	while (i < lenght_src)
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = src[i];
	return (new_src);
}
