/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:14:01 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/11 14:07:56 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_display_stack(t_pushswap *ps)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = ps->stack_a;
	current_b = ps->stack_b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("%d", current_a->content);
			current_a = current_a->next;
		}
		else
			printf(" ");
		printf(" ");
		if (current_b)
		{
			printf("%d\n", current_b->content);
			current_b = current_b->next;
		}
		else
			printf(" \n");
	}
	printf("- -\na b\n");
	printf("stack_a:%zu stack_b:%zu\n", ps->stack_a_size, ps->stack_b_size);
}

void	ft_check_one_argv(t_pushswap *ps, char *argv)
{
	int		i;
	char	**split;

	split = ft_split(argv, ' ');
	if (!split)
		exit(1);
	ps->argv = split;
	ps->allocated = 1;
	i = -1;
	while (split[++i])
		;
	ps->argc = i;
}

int	ft_check_and_init(t_pushswap *ps)
{
	t_stack	*_new;
	int		i;

	if (!ps->argc)
		exit(0);
	ps->count = 0;
	i = -1;
	while (++i < ps->argc)
		if (!ft_isint(ps->argv[i]))
			return (1);
	if (ft_isdup(ps->argv, ps->argc))
		return (1);
	ps->stack_a = NULL;
	i = -1;
	while (++i < ps->argc)
	{
		_new = ft_stacknew(ft_atoi(ps->argv[i]));
		if (!_new)
			return (ft_stackclear(&ps->stack_a));
		ft_stackadd_back(&ps->stack_a, _new);
	}
	ps->stack_b = NULL;
	ps->stack_a_size = ps->argc;
	ps->stack_b_size = 0;
	return (0);
}

void	push_swap_simple(t_pushswap *ps)
{
	(void) ps;
}
