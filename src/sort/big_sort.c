/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:40:57 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/05 18:00:12 by mlaffita         ###   ########.fr       */
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

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_memcpy(stack_a->stack_sort, stack_a->stack, (stack_a->count_gen * sizeof(int))); // copy stack
	bubble_sort(stack_a);
	fill_stack_radix(stack_a);
	(void)stack_b;
	// vrai radix
	
	//check le plus grand index ( avec number maxi sur stack radix ) 
	// check combien de fois on doit chifter les bits ( donc combien de bit a le index max )
	// faire boucle avec masque de bits pour checker 1st digit 
	// si == 1 reste dans la box a donc rotate
	// else , on va le push ds b 
	//
}