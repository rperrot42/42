/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:54:14 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/27 12:54:33 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_atoi(char *str);
void	ft_modulo(int nb, int modulo);
void	ft_multiplier(int nb, int multiplicator);
void	ft_add(int nb1, int nb2);
void	ft_division(int nb, int dividor);
void	ft_substraction(int nb, int substraction);

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	result(char **argv, void (*f[5])(int, int))
{
	int	nb1;
	int	nb2;
	int	lenargv2;

	lenargv2 = str_len(argv[1]);
	nb1 = ft_atoi(argv[0]);
	nb2 = ft_atoi(argv[2]);
	if (argv[1][0] == '%' && lenargv2 == 1)
		f[0](nb1, nb2);
	else if (argv[1][0] == '*' && lenargv2 == 1)
		f[1](nb1, nb2);
	else if (argv[1][0] == '+' && lenargv2 == 1)
		f[2](nb1, nb2);
	else if (argv[1][0] == '/' && lenargv2 == 1)
		f[3](nb1, nb2);
	else if (argv[1][0] == '-' && lenargv2 == 1)
		f[4](nb1, nb2);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	void	(*f[5])(int, int);

	if (argc == 4)
	{
		f[0] = &ft_modulo;
		f[1] = &ft_multiplier;
		f[2] = &ft_add;
		f[3] = &ft_division;
		f[4] = &ft_substraction;
		result(argv + 1, f);
	}
	return (0);
}
