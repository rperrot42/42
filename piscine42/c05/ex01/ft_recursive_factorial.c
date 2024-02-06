/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_iterative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:24:54 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/09 22:33:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb >= 2)
		return (ft_recursive_factorial(nb -1) * nb);
	return (0);
}
