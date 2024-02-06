/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:25:23 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/24 15:46:02 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char	*last, char *buffer, size_t	n);
size_t	ft_findnewline(char *s);
size_t	ft_strlen(char *s);
void	ft_memzero(char *s, size_t n);
size_t	ft_find_jump(char *s);
char	*ft_create_line(char *last);
void	ft_change_buffer(char *last, char *buffer);
char	*ft_free(char *last, char *return_value);
#endif