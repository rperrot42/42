/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_lstdouble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:31:10 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/17 12:41:21 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_double	*ft_crt_lstdouble(int value)
{
	t_list_double	*new_listdouble;

	new_listdouble = malloc(sizeof(t_list_double));
	if (!new_listdouble)
		return (NULL);
	new_listdouble -> value = value;
	return (new_listdouble);
}
