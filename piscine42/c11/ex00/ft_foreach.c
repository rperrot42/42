/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:40:23 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/18 20:02:33 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void ft_putnbr(int nb);
void	ft_foreach(int	*tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		i++;
	}
}
/*
int main(void)
{
	int	i[] = {1,2,3,4,5};

	ft_foreach(i, 5, &ft_putnbr);
}*/
