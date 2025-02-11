/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/11 18:30:05 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

void	print_stack(int *stack_a, int *count);

int	main (int argc, char *argv[])
{
	int count;
	int *stack_a;
	int *stack_b;

	if (argc < 2)
	{
		ft_error("Error argument", 2);
		return (1);
	}
	count = 0;
	if (input_check(argc, argv, &count)  == 1)
	{
		ft_error("Error input", 2);
		return (1);
	}
	init_stack(&stack_a, &stack_b, &count);
	extract_arg(argc, argv, stack_a);
	print_stack(stack_a, &count);
	
	free(stack_a);
	free(stack_b);
	printf("count :%d\n", count);
	return (0);
}

void	print_stack(int *stack_a, int *count)
{
	int i;

	i = 0;
	while (i < *count)
	{
		printf("%d, ", stack_a[i++]);
	}
}