/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:40:57 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 16:20:04 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(t_stack *stack_a)
{
	int i;
	int j;
	t_bool swapped;

	i = 0;
	while ( i < stack_a->count_gen)
	{
		swapped = FALSE;
		j = 0;
		while( j < (stack_a->count_gen - i - 1))
		{
			if(stack_a->stack_sort[j] > stack_a->stack_sort[j + 1])
			{
				swap(&stack_a->stack_sort[j], &stack_a->stack_sort[j + 1]);
				swapped = TRUE;
			}
			j++;
		}
		if (swapped == FALSE)
			break;
		i++;
	}
	
}

void	fill_stack_radix(t_stack *stack_a)
{
	int i;
	int j;
	
	i = 0;
	while(i < stack_a->count_gen)
	{
		j = 0;
		while(j < stack_a->count_gen)
		{
			if (stack_a->stack[i] == stack_a->stack_sort[j])
				{
					stack_a->stack_radix[i] = j;
				}
			j++;
		}
		i++;
	}
}

void radix(t_stack *stack_a, t_stack *stack_b)
{
	int max_index;
	int max_bit;
	int i;
	int j;
	
	i = 0;
	max_index = stack_a->count_gen - 1;
	max_bit = 0;
	while ((max_index >> max_bit) != 0)
		++max_bit;
	while ( i < max_bit)
	{
		j = 0;
		while ( j < stack_a->count_gen)
		{
			if (((stack_a->stack_radix[0] >> i) &1) == 1)
				rotate_a_big(stack_a);
			else
				push_b_big(stack_a, stack_b);
			j++;
		}
		while (stack_b->count_stck != 0)
			push_a_big(stack_a, stack_b);
		i++;
	}
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_memcpy(stack_a->stack_sort, stack_a->stack, (stack_a->count_gen * sizeof(int))); // copy stack
	bubble_sort(stack_a);
	fill_stack_radix(stack_a);
	// print_stack_radix(stack_a);
	radix(stack_a, stack_b);
	// print_stack_radix(stack_a);
}
