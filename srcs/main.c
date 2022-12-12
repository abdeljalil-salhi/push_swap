/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:13:55 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/12 22:58:39 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	ft_fill_args(t_pushswap *ps, int argc, char **argv)
{
	ps->argc = argc - 1;
	ps->argv = argv + 1;
}

static void	ft_free_main(t_pushswap *ps)
{
	int	i;

	i = -1;
	while (ps->argv[++i])
		free(ps->argv[i]);
	free(ps->argv);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	ps.allocated = 0;
	if (argc == 2)
		ft_check_one_argv(&ps, argv[1]);
	if (!ps.allocated)
		ft_fill_args(&ps, argc, argv);
	if (ft_check_and_init(&ps))
		ft_exit_error("Error");
	if (argc < 5)
		push_swap_simple(&ps);
	ft_display_stack(&ps);
	if (ps.allocated)
		ft_free_main(&ps);
	system("leaks push_swap");
	return (0);
}
