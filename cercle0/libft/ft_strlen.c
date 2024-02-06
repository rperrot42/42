/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:33 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/09 11:31:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	nb_char;

	nb_char = 0;
	while (str[nb_char] != '\0')
	{
		nb_char++;
	}
	return (nb_char);
}
