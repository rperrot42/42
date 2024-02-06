/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:49:36 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/17 18:39:04 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len_s;

	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	len_s = ft_strlen(s);
	if (write(fd, s, len_s) >= 0)
		return (len_s);
	return (-1);
}
