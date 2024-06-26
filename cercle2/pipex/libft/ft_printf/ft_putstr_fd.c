/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:49:36 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 18:59:24 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len_s;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len_s = ft_strlen(s);
	if (write(1, s, len_s) >= 0)
		return (len_s);
	return (-1);
}
