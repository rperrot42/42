/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:56:59 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/11 13:59:14 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		borne_inf;
	int		borne_sup;
	int		borne_avg;

	if (nb <= 0)
		return (0);
	borne_inf = 1;
	borne_sup = 46341;
	while (borne_inf != borne_sup - 1)
	{
		borne_avg = (borne_inf + borne_sup) / 2;
		if (borne_avg * borne_avg > nb)
			borne_sup = borne_avg;
		else
			borne_inf = borne_avg;
	}
	if (borne_inf * borne_inf == nb)
		return (borne_inf);
	return (0);
}
/*
int main(void)
{
	int		a = ft_sqrt(4);
	int		b = ft_sqrt(5);
	int		c = ft_sqrt(9);
	int		e = ft_sqrt(-1);
	int		d = ft_sqrt(2147395600);
	printf("%d %d %d %d %d", a, b, c, d, e);
}*/
