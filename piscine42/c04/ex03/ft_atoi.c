/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/08 18:37:31 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	value_atoi(char *str, int i, int *value)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*value *= 10;
		*value += str[i] - '0';
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	signe;

	signe = 0;
	i = 0;
	value = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	value_atoi(str, i, &value);
	if (signe % 2)
		value *= -1;
	return (value);
}
