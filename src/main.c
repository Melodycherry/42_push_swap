/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/04/06 13:05:29 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

void	init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->stack = NULL;
	stack_a->stack_sort = NULL;
	stack_a->stack_radix = NULL;
	stack_b->stack = NULL;
	stack_b->stack_sort = NULL;
	stack_b->stack_radix = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;

	init(&stack_a, &stack_b);
	if (argc < 2)
		return (1);
	count = 0;
	if (input_check(argc, argv, &count) == 1)
		return (ft_error(&stack_a, &stack_b));
	if (init_stack(&stack_a, &stack_b, count) == 1)
		return (1);
	if (extract_arg(argc, argv, stack_a.stack) == 1)
		return (ft_error(&stack_a, &stack_b));
	if (check_double(&stack_a))
		return (ft_error(&stack_a, &stack_b));
	if (count >= 2 && count <= 5)
		small_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b);
	return (0);
}
