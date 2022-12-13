/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:33:37 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 04:32:11 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*ft_stackdup(t_stack stack)
{
	t_stack	*tab;

	tab = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->content = stack.content;
	tab->pos = stack.pos;
	tab->target_pos = stack.target_pos;
	tab->final_rank = stack.final_rank;
	tab->cost_stack_a = stack.cost_stack_a;
	tab->cost_stack_b = stack.cost_stack_b;
	tab->next = NULL;
	return (tab);
}
