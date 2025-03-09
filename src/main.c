/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 16:56:25 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack);
void	print_stack_radix(t_stack *stack);

int	main (int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	int count;

	if (argc < 2)
		return(ft_error(&stack_a, &stack_b));
	count = 0;
	if (input_check(argc, argv, &count)  == 1)
		return(ft_error(&stack_a, &stack_b));
	if (init_stack(&stack_a, &stack_b, count) == 1)
		return (1);
	if (extract_arg(argc, argv, stack_a.stack) == 1)
		return(ft_error(&stack_a, &stack_b));
	if (check_double(&stack_a))
    	return(ft_error(&stack_a, &stack_b));
	if (count >= 2 && count <= 5)
		small_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b);
	return (0);
}



// a degager apres 
void	print_stack(t_stack *stack) // modif pour print le stack sort 
{
	int i;

	i = 0;
	while (i < stack->count_gen)
	{
		printf("%d, ", stack->stack[i++]);
	}
	printf("\n");
}

void	print_stack_radix(t_stack *stack) // modif pour print le stack sort 
{
	int i;

	i = 0;
	while (i < stack->count_gen)
	{
		printf("%d, ", stack->stack_radix[i++]);
	}
	printf("\n");
}


//print_stack(&stack_a);
//print_stack_radix(&stack_a);
	
//test print mini maxi 
	// printf("mini : %d\n", nbr_mini(&stack_a));
	// printf("mini index : %d\n", nbr_mini_index(&stack_a));
	// printf("maxi : %d\n", nbr_maxi(stack_a.stack, stack_a.count));
	
	// print pour tester move
	// print_stack(stack_a.stack, &count); 
	// print_stack(stack_b.stack, &count); 
	// push_b(stack_a.stack, stack_b.stack, &count);
	// print_stack(stack_a.stack, &count); 
	// print_stack(stack_b.stack, &count); 