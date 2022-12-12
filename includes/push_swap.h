/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:14:07 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/11 14:07:50 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_a_size;
	size_t	stack_b_size;
	int		count;
	int		allocated;
	int		argc;
	char	**argv;
}	t_pushswap;

void	ft_check_one_argv(t_pushswap *ps, char *argv);
int		ft_check_and_init(t_pushswap *ps);
void	ft_display_stack(t_pushswap *ps);
void	push_swap_simple(t_pushswap *ps);

void	swap_a(t_pushswap *ps, int display);
void	swap_b(t_pushswap *ps, int display);
void	swap_ab(t_pushswap *ps, int display);
void	push_a(t_pushswap *ps, int display);
void	push_b(t_pushswap *ps, int display);
void	rotate_a(t_pushswap *ps, int display);
void	rotate_b(t_pushswap *ps, int display);
void	rotate_ab(t_pushswap *ps, int display);
void	reverse_rotate_a(t_pushswap *ps, int display);
void	reverse_rotate_b(t_pushswap *ps, int display);
void	reverse_rotate_ab(t_pushswap *ps, int display);

int		ft_isint(char *str);
int		ft_isdup(char **argvs, int argc);

void	ft_exit_error(char *str);

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stackclear(t_stack **stack);
void	ft_stackadd_front(t_stack **stack, t_stack *_new);
void	ft_stackadd_back(t_stack **stack, t_stack *_new);

#endif
