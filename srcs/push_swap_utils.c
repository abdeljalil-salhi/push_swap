/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:14:21 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/13 03:33:56 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isint(char *str)
{
	long int	n;
	int			s;
	int			i;

	if (str[0] == '\0')
		return (0);
	n = 0;
	s = 1;
	i = -1;
	while (str[++i] == 32 || (8 < str[i] && str[i] < 14))
		;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			s *= -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + str[i++] - 48;
	}
	return ((n * s) <= INT_MAX && (n * s) >= INT_MIN);
}

int	ft_isdup(char **argvs, int argc)
{
	int	*tab;
	int	i;
	int	j;
	int	found;

	found = 1;
	tab = (int *) malloc((argc) * sizeof(int));
	if (!tab)
		return (1);
	i = -1;
	while (++i < argc)
		tab[i] = ft_atoi(argvs[i]);
	i = -1;
	while (++i < argc && found)
	{
		j = i;
		while (++j < argc && found)
			if (tab[i] == tab[j])
				found = 0;
	}
	free(tab);
	return (!found);
}
