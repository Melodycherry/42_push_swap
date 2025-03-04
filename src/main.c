/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/04 18:11:34 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

void	print_stack(int *stack_a, int *count);

int	main (int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int count;

	if (argc < 2)
		return(ft_error());
	count = 0;
	if (input_check(argc, argv, &count)  == 1)
		return(ft_error());
	init_stack(&stack_a, &stack_b, count);
	if (extract_arg(argc, argv, stack_a.stack) == 1)
		return(ft_error());
	if (check_double(&stack_a))
    	return(ft_error());

	//test print mini maxi 
	// printf("mini : %d\n", nbr_mini(&stack_a));
	// printf("mini index : %d\n", nbr_mini_index(&stack_a));
	// printf("maxi : %d\n", nbr_maxi(stack_a.stack, stack_a.count));
	
	if (count >= 2 && count <= 5)
		small_sort(&stack_a, &stack_b);
	//else if
		//big_sort()

	// print pour tester move
	// print_stack(stack_a.stack, &count); 
	// print_stack(stack_b.stack, &count); 
	// push_b(stack_a.stack, stack_b.stack, &count);
	// print_stack(stack_a.stack, &count); 
	// print_stack(stack_b.stack, &count); 
	
	free(stack_a.stack);
	free(stack_b.stack);
	//printf("count :%d\n", count);
	return (0);
}

// a degager apres 
void	print_stack(int *stack_a, int *count)
{
	int i;

	i = 0;
	while (i < *count)
	{
		printf("%d, ", stack_a[i++]);
	}
	printf("\n");
}
