/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:31:44 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/15 01:16:44 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_highest_rank(t_stack *stack)
{
	t_stack	*current;
	int		highest;

	current = stack;
	highest = current->final_rank;
	while (current)
	{
		if (current->final_rank > highest)
			highest = current->final_rank;
		current = current->next;
	}
	return (highest);
}

void	ft_quick_sort_stack(t_pushswap *ps)
{
	int	highest;

	highest = ft_get_highest_rank(ps->stack_a);
	if (ps->stack_a->final_rank == highest)
		rotate_a(ps, 1);
	else if (ps->stack_a->next->final_rank == highest)
		reverse_rotate_a(ps, 1);
	if (ps->stack_a->final_rank > ps->stack_a->next->final_rank)
		swap_a(ps, 1);
}
