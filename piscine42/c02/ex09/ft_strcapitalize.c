/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:50:23 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/11 12:09:15 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	upper_case;

	upper_case = 1;
	i = 0;
	while (str[i])
	{
		if (upper_case && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		if (!upper_case && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A'))
			upper_case = 1;
		else if (str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a'))
			upper_case = 1;
		else
			upper_case = 0;
		i++;
	}
	return (str);
}
/*#include <stdio.h>

int main()
{
	char a[] = "abcdedeh.de.deUUE deokde";
	ft_strcapitalize(a);
	printf("%s",a);
}*/
