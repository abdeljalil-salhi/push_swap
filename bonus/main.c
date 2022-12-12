/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:39:15 by absalhi           #+#    #+#             */
/*   Updated: 2022/11/30 16:25:36 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	char		*buf;

	ps.allocated = 0;
	if (argc == 2)
		ft_check_one_argv(&ps, argv[1]);
	if (!ps.allocated)
		ft_fill_args(&ps, argc, argv);
	if (ft_check_and_init(&ps))
		ft_exit_error("Error");
	while (1)
	{
		buf = get_next_line(0);
		if (!buf || *buf == '\n')
		{
			free(buf);
			ft_stacksorted(&ps);
			if (ps.allocated)
				ft_free_main(&ps);
			exit(0);
		}
		ft_do(&ps, buf);
		free(buf);
	}
}
