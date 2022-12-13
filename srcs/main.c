/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:13:55 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 03:29:52 by absalhi          ###   ########.fr       */
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

static void	ft_set_ranks(t_pushswap *ps, size_t size)
{
	t_stack	*current;
	t_stack	*highest;
	int		stocked;

	while (--size)
	{
		highest = NULL;
		stocked = INT_MIN;
		current = ps->stack_a;
		while (current)
		{
			if (current->content == INT_MIN && current->final_rank == DEFAULT)
				current->final_rank = 1;
			if (current->content > stocked && current->final_rank == DEFAULT)
			{
				stocked = current->content;
				highest = current;
				current = ps->stack_a;
			}
			else
				current = current->next;
		}
		if (highest)
			highest->final_rank = size;
	}
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
	if (ft_is_stack_sorted(ps.stack_a))
		return (0);
	ft_set_ranks(&ps, ps.stack_a_size + 1);
	ft_display_stack(&ps);
	push_swap(&ps);
	ft_display_stack(&ps);
	if (ps.allocated)
		ft_free_main(&ps);
	return (0);
}
