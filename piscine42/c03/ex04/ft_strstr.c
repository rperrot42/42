/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:18:37 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/12 17:33:29 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i_occurence;

	i_occurence = 0;
	while (*str)
	{
		if (to_find[i_occurence] == '\0')
			return (str - i_occurence);
		if (*str == to_find[i_occurence])
			i_occurence++;
		else
			i_occurence = 0;
		str++;
	}
	if (to_find[i_occurence] == '\0')
		return (str - i_occurence);
	return (0);
}
