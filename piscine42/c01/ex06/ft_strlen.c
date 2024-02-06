/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:03:10 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 19:08:23 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
/*int main (void)
{
        char a[]="bonjour";
        int b=ft_strlen(&a[0]);
        printf("%d",b);

}*/
