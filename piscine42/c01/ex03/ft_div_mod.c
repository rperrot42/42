/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:22:02 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/06 17:29:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int	main(void)
{
	int a=9;
	int b=5;
	int div;
	int mod;
	ft_div_mod(a,b,&div,&mod);
	printf("%d %d", div,mod);
}*/
