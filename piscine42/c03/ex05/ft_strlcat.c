/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:02:00 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/13 12:04:09 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = ft_strlen(dest);
	if (j <= size)
		return (ft_strlen(src) + size);
	while (src[i] && (size - 1) < (j + i))
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = 0;
	return (j + ft_strlen(src));
}
/*
#include <stdlib.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	char a[45454] = "bonjour";
	char *b = argv[2];
	unsigned int size = atoi(argv[3]);
	printf("%d\n", ft_strlcat(a,b,size));
	printf("%d",a[12]);
}*/
