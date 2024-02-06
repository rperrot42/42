/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:21:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 18:54:44 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_base_long(unsigned long long int nb, char *base, \
	unsigned long long int len_base);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);

#endif