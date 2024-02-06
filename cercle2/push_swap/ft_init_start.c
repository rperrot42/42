/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:38:58 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/27 18:13:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_malloc_all_info(t_all_info *all_info, int argc, \
t_bool split, char **argv);

static void	ft_create_argv_split(int argc, char **argv, t_all_info *all_info);

static void	ft_free_split_error(char **argv, t_bool split, \
t_all_info *all_info);

void	ft_init_start(t_all_info *all_info, int argc, char **argv, t_bool split)
{
	int			i;
	long int	value_atoi;

	all_info ->stack_a = NULL;
	all_info -> stack_b = NULL;
	all_info->tab_operation = NULL;
	if (argc == 1 && split == FALSE)
	{
		ft_create_argv_split(argc, argv, all_info);
		return ;
	}
	ft_malloc_all_info(all_info, argc, split, argv);
	i = -1;
	while (++i < argc)
	{
		value_atoi = ft_simpleatoi(argv[i]);
		if (value_atoi > 2147483647 || value_atoi < -2147483648)
			ft_free_error(all_info);
		if (ft_is_in_tab(all_info -> stack_a, value_atoi) == TRUE)
			ft_free_error(all_info);
		(all_info -> stack_a->tab_stack)[i] = value_atoi;
		all_info -> stack_a->len = i + 1;
	}
}

static void	ft_malloc_all_info(t_all_info *all_info, \
int argc, t_bool split, char **argv)
{
	all_info -> stack_a = malloc(sizeof(t_tab_stack));
	if (!all_info -> stack_a)
		ft_free_split_error(argv, split, all_info);
	all_info ->stack_a -> tab_stack = NULL;
	all_info -> stack_b = malloc(sizeof(t_tab_stack));
	if (!all_info -> stack_b)
		ft_free_split_error(argv, split, all_info);
	all_info ->stack_b -> tab_stack = NULL;
	all_info -> tab_operation = malloc(sizeof(t_tab_operation));
	if (!all_info -> tab_operation)
		ft_free_split_error(argv, split, all_info);
	all_info ->tab_operation ->operations = NULL;
	all_info -> stack_a->tab_stack = malloc(sizeof(int) * (argc));
	if (!all_info -> stack_a->tab_stack)
		ft_free_split_error(argv, split, all_info);
	all_info -> stack_b->tab_stack = malloc(sizeof(t_operation) * (argc));
	if (!all_info -> stack_b->tab_stack)
		ft_free_split_error(argv, split, all_info);
	all_info -> tab_operation->operations = \
malloc(ft_log(argc) * argc * sizeof(t_operation));
	if (!all_info -> tab_operation->operations)
		ft_free_split_error(argv, split, all_info);
	all_info -> tab_operation->len = 0;
	all_info -> stack_a->len = 0;
	all_info -> stack_b->len = 0;
}

static void	ft_create_argv_split(int argc, char **argv, t_all_info *all_info)
{
	char	**split;

	split = ft_split(argv[0], ' ');
	argc = 0;
	if (!split)
		ft_free_error(all_info);
	while (split[argc])
		argc++;
	ft_init_start(all_info, argc, split, TRUE);
	while (argc--)
		free(split[argc]);
	free(split);
}

static void	ft_free_split_error(char **argv, t_bool split, t_all_info *all_info)
{
	int	i;

	if (split == TRUE)
	{
		i = -1;
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
	ft_free_error(all_info);
}
