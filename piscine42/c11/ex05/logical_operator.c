/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:59:30 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/19 13:35:35 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_modulo(int nb, int modulo)
{
	if (modulo == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(nb % modulo);
}

void	ft_multiplier(int nb, int multiplicator)
{
	ft_putnbr(nb * multiplicator);
}

void	ft_add(int nb1, int nb2)
{
	ft_putnbr(nb1 + nb2);
}

void	ft_division(int nb, int dividor)
{
	if (dividor == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(nb / dividor);
}

void	ft_substraction(int nb, int substraction)
{
	ft_putnbr(nb - substraction);
}
