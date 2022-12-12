/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:53 by absalhi           #+#    #+#             */
/*   Updated: 2022/11/30 16:10:04 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*tab;

	tab = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

int	ft_stackclear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return (1);
	current = (*stack);
	next = (*stack);
	while (current)
	{
		next = next->next;
		free(current);
		current = next;
	}
	*stack = NULL;
	return (1);
}

void	ft_stackadd_back(t_stack **stack, t_stack *_new)
{
	t_stack	*current;

	if (!stack || !_new)
		return ;
	current = (*stack);
	if (!current)
	{
		*stack = _new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = _new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *_new)
{
	if (!_new)
		return ;
	if (!stack)
	{
		*stack = _new;
		return ;
	}
	_new->next = (*stack);
	(*stack) = _new;
}
