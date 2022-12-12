/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:45:45 by absalhi           #+#    #+#             */
/*   Updated: 2022/11/30 16:53:54 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_pushswap *ps, int display)
{
	t_stack	*next;

	if (ps->stack_b_size < 1)
		return ;
	next = ps->stack_b->next;
	ft_stackadd_front(&ps->stack_a, ps->stack_b);
	ps->stack_b = next;
	ps->stack_a_size++;
	ps->stack_b_size--;
	if (display)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_pushswap *ps, int display)
{
	t_stack	*next;

	if (ps->stack_a_size < 1)
		return ;
	next = ps->stack_a->next;
	ft_stackadd_front(&ps->stack_b, ps->stack_a);
	ps->stack_a = next;
	ps->stack_a_size--;
	ps->stack_b_size++;
	if (display)
		ft_putstr_fd("pb\n", 1);
}

void	rotate_ab(t_pushswap *ps, int display)
{
	rotate_a(ps, display);
	rotate_b(ps, display);
}

void	reverse_rotate_ab(t_pushswap *ps, int display)
{
	reverse_rotate_a(ps, display);
	reverse_rotate_b(ps, display);
}
