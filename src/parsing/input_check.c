/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:49:00 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 19:48:58 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

static int	parse_arg(char *p_arg, int *count);

int	input_check(int argc, char *argv[], int *count)
{
	int		i;
	char	*p_arg;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			return (1);
		p_arg = argv[i];
		if (parse_arg(p_arg, count) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_arg(char *p_arg, int *count)
{
	int	i;

	i = 0;
	while (p_arg[i])
	{
		if (!ft_isdigit(p_arg[i]) && !ft_isspace(p_arg[i])
			&& p_arg[i] != '-' && p_arg[i] != '+')
			return (1);
		while (ft_isspace(p_arg[i]))
			i++;
		if (p_arg[i] == '+' || p_arg[i] == '-')
		{
			if (!ft_isdigit(p_arg[i + 1]))
				return (1);
			i++;
		}
		while (ft_isdigit(p_arg[i]))
			i++;
		(*count)++;
	}
	if (p_arg[i - 1] == ' ')
		(*count)--;
	return (0);
}

int	check_double(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->count_gen)
	{
		j = i + 1;
		while (j < stack_a->count_gen)
		{
			if (stack_a->stack[i] == stack_a->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
