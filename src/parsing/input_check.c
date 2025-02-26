/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:52:09 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/05 17:35:44 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

static int	parse_arg(char *p_arg, int *count);

int	input_check(int argc, char *argv[], int *count)
{
	int i;
	char	*p_arg;

	i = 1;
	while (i < argc)
	{
		p_arg = argv[i];
		if (parse_arg(p_arg, count) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_arg(char *p_arg, int *count)
{
	int i;
	
	i = 0;
	while (p_arg[i])
	{
		if (!ft_isdigit(p_arg[i]) && !ft_isspace(p_arg[i]) && p_arg[i] != '-' && p_arg[i] != '+')
			return (1);
		while (ft_isspace(p_arg[i]))
			i++;
		if (p_arg[i] == '+' || p_arg[i] == '-')
			i++;
		while (ft_isdigit(p_arg[i]))
			i++;
		(*count)++;
	}
	return (0);
}

int	check_double(int *stack, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
