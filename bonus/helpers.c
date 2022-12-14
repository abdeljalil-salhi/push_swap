/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:39:48 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/02 18:50:01 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_init_arrays(int (*operations[11])(t_pushswap *, int),
		char *instructions[11])
{
	operations[0] = &swap_a;
	operations[1] = &swap_b;
	operations[2] = &swap_ab;
	operations[3] = &push_a;
	operations[4] = &push_b;
	operations[5] = &rotate_a;
	operations[6] = &rotate_b;
	operations[7] = &rotate_ab;
	operations[8] = &reverse_rotate_a;
	operations[9] = &reverse_rotate_b;
	operations[10] = &reverse_rotate_ab;
	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
}

void	ft_do(t_pushswap *ps, char *buf)
{
	int		(*operations[11])(t_pushswap *, int);
	char	*instructions[11];
	int		i;

	ft_init_arrays(operations, instructions);
	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(instructions[i], buf, ft_strlen(instructions[i])))
			if (buf[ft_strlen(instructions[i])] == '\n')
				break ;
	}
	if (i > 10)
		ft_exit_error("Error");
	operations[i](ps, 0);
}

void	ft_stacksorted(t_pushswap *ps)
{
	t_stack		*current;
	long int	n;

	if (ps->stack_b_size)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	n = (long int) ps->stack_a->content - 1;
	current = ps->stack_a;
	while (current)
	{
		if (current->content < n)
		{
			ft_putstr_fd("KO\n", 1);
			exit(0);
		}
		n = current->content;
		current = current->next;
	}
	ft_putstr_fd("OK\n", 1);
}
