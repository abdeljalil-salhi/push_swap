/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:14:15 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 03:48:51 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_pushswap *ps, int display)
{
	if (ps->stack_a_size < 2)
		return ;
	ft_stackadd_front(&ps->stack_a, ft_stackdup(*(ps->stack_a->next)));
	free(ps->stack_a->next->next);
	ps->stack_a->next->next = ps->stack_a->next->next->next;
	if (display)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_pushswap *ps, int display)
{
	if (ps->stack_b_size < 2)
		return ;
	ft_stackadd_front(&ps->stack_b, ft_stackdup(*(ps->stack_b->next)));
	free(ps->stack_b->next->next);
	ps->stack_b->next->next = ps->stack_b->next->next->next;
	if (display)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_pushswap *ps, int display)
{
	swap_a(ps, display);
	swap_b(ps, display);
}
