/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:21:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/20 13:35:18 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base_long(unsigned long long int nb, char *base, \
	unsigned long long int len_base);
size_t	ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);

#endif