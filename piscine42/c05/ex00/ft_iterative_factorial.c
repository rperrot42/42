/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:06:18 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/09 22:36:00 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	resultat;

	resultat = 1;
	if (nb == 0)
		return (1);
	if (nb <= 0)
		return (0);
	while (nb >= 1)
	{
		resultat *= nb;
		nb--;
	}
	return (resultat);
}
