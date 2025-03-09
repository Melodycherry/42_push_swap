/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:09 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 16:53:50 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

int	init_stack(t_stack *stack_a, t_stack *stack_b, int count)
{
	stack_a->stack = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack = (int *) ft_calloc(count, sizeof(int));
	stack_a->stack_radix = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack_radix = (int *) ft_calloc(count, sizeof(int));
	stack_a->stack_sort = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack_sort = (int *) ft_calloc(count, sizeof(int));
	if (!stack_a->stack || !stack_b->stack
		|| !stack_a->stack_radix || !stack_b->stack_radix || !stack_a->stack_sort)
		return (1);
	stack_a->count_gen = count;
	stack_b->count_gen = count;
	stack_a->count_stck = count;
	stack_b->count_stck = 0;
	stack_a->maxi = 0;
	stack_b->maxi = 0;
	stack_a->mini = 0;
	stack_b->mini = 0;
	stack_a->min_index = 0;
	stack_b->min_index = 0;
	return (0);
}

int extract_arg(int argc, char *argv[], int *stack_a)
{
	char	*p_arg;
	int i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < argc)
	{
		p_arg = argv[i];
		if (insert_to_stack(p_arg, stack_a, &j) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	*extract_number(char *p_arg, int *i, int *is_neg)
{
		char *num;
		char *dup;

		num = NULL;
		*is_neg = 0;
		while (ft_isspace(p_arg[*i]))
			(*i)++;
		if (p_arg[*i] == '+' || p_arg[*i] == '-')
		{
			if (p_arg[*i] == '-')
			{
				*is_neg = 1;
				num = p_arg + *i;
			}
			(*i)++;
		}
		if (!(*is_neg))
			num = p_arg + *i;
		while (ft_isdigit(p_arg[*i]))
			(*i)++;
		dup = ft_strndup(num, p_arg + *i - num);
		return (dup);
}

int	insert_to_stack(char *p_arg, int *stack_a, int *j)
{
	int i;
	int	is_neg;
	char *num;
	long temp; 
	
	i = 0;
	temp = 0;
	num = NULL;
	while (p_arg[i])
	{
		num = extract_number(p_arg, &i, &is_neg);
		if (!num)
			return (1);
		temp = ft_atol(num);
		free(num);
		if ( (temp > INT_MAX) || (temp < INT_MIN))
			return (1);
		stack_a[*j] = (int)temp;
		(*j)++;
	}
	return (0);
}
