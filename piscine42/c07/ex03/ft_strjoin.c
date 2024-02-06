/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:17:44 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 19:52:01 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	nb_char;

	nb_char = 0;
	while (str[nb_char] != '\0')
	{
		nb_char++;
	}
	return (nb_char);
}

void	ft_strcat(int *total_len, char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[*total_len] = src[i];
		i++;
		*total_len = *total_len + 1;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*tab_char;

	total_len = ft_strlen(sep) * (size - 1);
	i = -1;
	while (++i < size)
		total_len += ft_strlen(strs[i]);
	if (!size)
		total_len = 0;
	tab_char = malloc(sizeof(char) * (total_len + 1));
	if (!tab_char)
		return (0);
	total_len = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(&total_len, tab_char, strs[i]);
		if (i < (size - 1))
			ft_strcat(&total_len, tab_char, sep);
		i++;
	}
	tab_char[total_len] = 0;
	return (tab_char);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	char **a = argv + 1;
	char b[] = " caca ";
	char *c = ft_strjoin(argc - 1, a, b);
	printf("%s", c);
	free(c);

}*/
