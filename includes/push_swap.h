/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:14:26 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/15 01:14:50 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

# define DEFAULT -69

typedef struct s_stack
{
	int				content;
	int				pos;
	int				target_pos;
	int				final_rank;
	int				cost_stack_a;
	int				cost_stack_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_a_size;
	size_t	stack_b_size;
	int		allocated;
	int		argc;
	char	**argv;
}	t_pushswap;

struct s_find_move
{
	t_pushswap	*ps;
	int			cost_stack_a;
	int			cost_stack_b;
};

void	ft_check_one_argv(t_pushswap *ps, char *argv);
int		ft_check_and_init(t_pushswap *ps);

void	push_swap(t_pushswap *ps);

void	ft_quick_sort_stack(t_pushswap *ps);

void	ft_sort_stack(t_pushswap *ps);
void	ft_set_pos(t_stack *stack);
void	ft_set_target_pos(t_pushswap *ps);
void	ft_exec_move(struct s_find_move ret);
void	ft_get_least_pos_by_ranking(t_stack *stack, int *least_pos);

int		swap_a(t_pushswap *ps, int display);
int		swap_b(t_pushswap *ps, int display);
int		swap_ab(t_pushswap *ps, int display);
int		push_a(t_pushswap *ps, int display);
int		push_b(t_pushswap *ps, int display);
int		rotate_a(t_pushswap *ps, int display);
int		rotate_b(t_pushswap *ps, int display);
int		rotate_ab(t_pushswap *ps, int display);
int		reverse_rotate_a(t_pushswap *ps, int display);
int		reverse_rotate_b(t_pushswap *ps, int display);
int		reverse_rotate_ab(t_pushswap *ps, int display);

int		ft_isint(char *str);
int		ft_isdup(char **argvs, int argc);

void	ft_exit_error(char *str);

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackdup(t_stack stack);
int		ft_stackclear(t_stack **stack);
void	ft_stackadd_front(t_stack **stack, t_stack *_new);
void	ft_stackadd_back(t_stack **stack, t_stack *_new);
int		ft_is_stack_sorted(t_stack *stack);

#endif
