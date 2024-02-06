/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:54:16 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 20:29:47 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lenght_src;

	lenght_src = 0;
	i = 0;
	while (src[lenght_src])
		lenght_src++;
	if (size < 1)
		return (lenght_src);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (lenght_src);
}
