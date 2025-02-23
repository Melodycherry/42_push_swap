/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:09 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/23 12:31:35 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

void	init_stack(int **stack_a, int **stack_b, int *count)
{
	*stack_a = (int *) ft_calloc(*count, sizeof(int));
	*stack_b = (int *) ft_calloc(*count, sizeof(int));
	if (!*stack_a || !stack_b)
		return ;
}

void extract_arg(int argc, char *argv[], int *stack_a)
{
	char	*p_arg;
	int i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < argc)
	{
		p_arg = argv[i];
		insert_to_stack(p_arg, stack_a, j);
		i++;
		j++;
	}
}

void	insert_to_stack(char *p_arg, int *stack_a, int j)
{
	int i;
	int	is_neg;
	char *num;
	
	i = 0;
	num = NULL;
	while (p_arg[i])
	{
		is_neg = 0;
		while (ft_isspace(p_arg[i]))
			i++;
		if (p_arg[i] == '+' || p_arg[i] == '-')
		{
			if (p_arg[i] == '-')
			{
				is_neg = 1;
				num = p_arg + i;
			}
			i++;
		}
		if (!is_neg)
			num = p_arg + i;
		while (ft_isdigit(p_arg[i]))
			i++;
		num = ft_strndup(num, p_arg + i - num);
		if (!num)
			return ;
		stack_a[j] = ft_atoi(num);
		j++;
		free(num);
	}
}