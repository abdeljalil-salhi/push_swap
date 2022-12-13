/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:52:02 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 05:50:43 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_stackprelast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	current = stack;
	while (current->next->next)
		current = current->next;
	return (current);
}

int	rotate_a(t_pushswap *ps, int display)
{
	if (ps->stack_a_size < 2)
		return (0);
	ft_stackadd_back(&ps->stack_a, ft_stackdup(*(ps->stack_a)));
	free(ps->stack_a);
	ps->stack_a = ps->stack_a->next;
	if (display)
		ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rotate_b(t_pushswap *ps, int display)
{
	if (ps->stack_b_size < 2)
		return (0);
	ft_stackadd_back(&ps->stack_b, ft_stackdup(*(ps->stack_b)));
	free(ps->stack_b);
	ps->stack_b = ps->stack_b->next;
	if (display)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

int	reverse_rotate_a(t_pushswap *ps, int display)
{
	t_stack	*last;

	if (ps->stack_a_size < 2)
		return (0);
	last = ft_stacklast(ps->stack_a);
	ft_stackadd_front(&ps->stack_a, ft_stackdup(*(last)));
	ft_stackprelast(ps->stack_a)->next = NULL;
	free(last);
	if (display)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	reverse_rotate_b(t_pushswap *ps, int display)
{
	t_stack	*last;

	if (ps->stack_b_size < 2)
		return (0);
	last = ft_stacklast(ps->stack_b);
	ft_stackadd_front(&ps->stack_b, ft_stackdup(*(last)));
	ft_stackprelast(ps->stack_b)->next = NULL;
	free(last);
	if (display)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}
