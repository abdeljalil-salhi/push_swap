/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:32:51 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 05:10:54 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_get_target(t_pushswap *ps, int stack_b_rank,
						int closest_rank, int target_pos)
{
	t_stack	*crt;

	crt = ps->stack_a;
	while (crt)
	{
		if (crt->final_rank > stack_b_rank && crt->final_rank < closest_rank)
		{
			closest_rank = crt->final_rank;
			target_pos = crt->pos;
		}
		crt = crt->next;
	}
	if (closest_rank != INT_MAX)
		return (target_pos);
	crt = ps->stack_a;
	while (crt)
	{
		if (crt->final_rank < closest_rank)
		{
			closest_rank = crt->final_rank;
			target_pos = crt->pos;
		}
		crt = crt->next;
	}
	return (target_pos);
}

static void	ft_set_pos(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = -1;
	current = stack;
	while (current)
	{
		current->pos = ++i;
		current = current->next;
	}
}

void	ft_set_target_pos(t_pushswap *ps)
{
	t_stack	*current;
	int		target_pos;

	current = ps->stack_b;
	ft_set_pos(ps->stack_a);
	ft_set_pos(ps->stack_b);
	target_pos = 0;
	while (current)
	{
		target_pos = ft_get_target(ps, current->final_rank,
				INT_MAX, target_pos);
		current->target_pos = target_pos;
		current = current->next;
	}
}
