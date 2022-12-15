/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:32:05 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/15 01:16:47 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_b_and_prepare_quick_sort(t_pushswap *ps, size_t size)
{
	size_t	pushed_to_b;
	int		i;

	pushed_to_b = 0;
	i = -1;
	while (size > 6 && (size_t)++i < size && pushed_to_b < size / 2)
	{
		if ((size_t)ps->stack_a->final_rank <= size / 2)
			pushed_to_b += push_b(ps, 1);
		else
			rotate_a(ps, 1);
	}
	while (size - pushed_to_b > 3)
		pushed_to_b += push_b(ps, 1);
}

static void	ft_get_cost(t_pushswap *ps)
{
	t_stack	*crt_a;
	t_stack	*crt_b;

	crt_a = ps->stack_a;
	crt_b = ps->stack_b;
	while (crt_b)
	{
		crt_b->cost_stack_b = crt_b->pos;
		if ((size_t)crt_b->pos > ps->stack_b_size / 2)
			crt_b->cost_stack_b = (ps->stack_b_size - crt_b->pos) * -1;
		crt_b->cost_stack_a = crt_b->target_pos;
		if ((size_t)crt_b->target_pos > ps->stack_a_size / 2)
			crt_b->cost_stack_a = (ps->stack_a_size - crt_b->target_pos) * -1;
		crt_b = crt_b->next;
	}
}

static void	ft_find_move(t_pushswap *ps)
{
	struct s_find_move	ret;
	t_stack				*c;
	int					least;

	least = INT_MAX;
	c = ps->stack_b;
	while (c)
	{
		if (ft_abs(c->cost_stack_a) + ft_abs(c->cost_stack_b) < ft_abs(least))
		{
			least = ft_abs(c->cost_stack_b) + ft_abs(c->cost_stack_a);
			ret.cost_stack_a = c->cost_stack_a;
			ret.cost_stack_b = c->cost_stack_b;
		}
		c = c->next;
	}
	ret.ps = ps;
	ft_exec_move(ret);
}

static void	ft_rotate_stack(t_pushswap *ps, t_stack *stack, size_t size)
{
	int	least_pos;

	ft_set_pos(stack);
	least_pos = stack->pos;
	ft_get_least_pos_by_ranking(stack, &least_pos);
	if ((size_t)least_pos > size / 2)
		while ((size_t)least_pos < size)
			least_pos += reverse_rotate_a(ps, 1);
	else
		while (least_pos)
			least_pos -= rotate_a(ps, 1);
}

void	ft_sort_stack(t_pushswap *ps)
{
	ft_push_b_and_prepare_quick_sort(ps, ps->stack_a_size);
	ft_quick_sort_stack(ps);
	while (ps->stack_b)
	{
		ft_set_target_pos(ps);
		ft_get_cost(ps);
		ft_find_move(ps);
	}
	if (!ft_is_stack_sorted(ps->stack_a))
		ft_rotate_stack(ps, ps->stack_a, ps->stack_a_size);
}
