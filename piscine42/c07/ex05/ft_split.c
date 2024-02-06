/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:25 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 15:15:01 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_charset(char c, char *charset);

char	*crt_word(char *str, char *charset)
{
	int		i;
	char	*tab;
	int		len;

	i = 0;
	while (str[i] && is_charset(str[i], charset))
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (tab);
	len = i;
	i = 0;
	while (i < len)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	len_tab(char *str, char *charset)
{
	int	i;
	int	len_tab;

	i = 0;
	len_tab = 0;
	while (str[i])
	{
		while (!is_charset(str[i], charset) && str[i])
			i++;
		if (is_charset(str[i], charset) && str[i])
			len_tab++;
		while (is_charset(str[i], charset) && str[i])
			i++;
	}
	return (len_tab + 1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	int		j;

	tab = malloc(sizeof (char *) * len_tab(str, charset));
	i = 0;
	j = 0;
	if (tab == NULL)
		return (tab);
	while (str[i])
	{
		while (str[i] && !is_charset(str[i], charset))
			i++;
		if (is_charset(str[i], charset) && str[i])
		{
			tab[j] = crt_word(str + i, charset);
			j++;
		}
		while (str[i] && is_charset(str[i], charset))
			i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	char **a = ft_split(argv[1],argv[2]);
	int i = 0;
	while (a[i])
	{
		printf("%s\n", a[i]);
		free(a[i]);
		i++;
	}
	free(a);

}*/
