/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:41:03 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/02 20:03:41 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack_a) // ok fonctionne 
{
	int i;

	i = 0;
	while ( i < stack_a->count - 1)
	{
		if (stack_a->stack[i] > stack_a->stack[i + 1])
			return (0);
		i++;
	}
	return(1);
}

void sort_3(t_stack *stack_a) // ok teste fonctionne 
{
	if (stack_a->stack[0] == stack_a->mini && stack_a->stack[1] == stack_a->maxi)
	{
		reverse_rotate_a(stack_a->stack, &stack_a->count);
		swap_a(stack_a->stack);
	}
	else if (stack_a->stack[1] == stack_a->maxi && stack_a->stack[2] == stack_a->mini)
		reverse_rotate_a(stack_a->stack, &stack_a->count);
	else if (stack_a->stack[1] == stack_a->mini && stack_a->stack[2] == stack_a->maxi)
		swap_a(stack_a->stack);
	else if (stack_a->stack[0] == stack_a->maxi && stack_a->stack[1] == stack_a->mini)
		rotate_a(stack_a->stack, &stack_a->count);
	else if (stack_a->stack[0] == stack_a->maxi && stack_a->stack[2] == stack_a->mini)
	{
		rotate_a(stack_a->stack, &stack_a->count);
		swap_a(stack_a->stack);
	}
}

void sort_4(t_stack *stack_a, t_stack *stack_b) // a checker encore car va etre trop long ... 
{
	if (stack_a->stack[0] == stack_a->mini )
	{
		int count = stack_a->count;
		push_b(stack_a->stack, stack_b->stack, &count);
		stack_a->count--;
        stack_b->count++;
		stack_a->mini = nbr_mini(stack_a->stack, stack_a->count);
   		stack_a->maxi = nbr_maxi(stack_a->stack, stack_a->count);
		sort_3(stack_a);
		push_a(stack_a->stack, stack_b->stack, &count);
		stack_a->count++;
        stack_b->count--;
	}
	//continuer les 4 autres possibilites 
}

// void sort_5(t_stack *stack_a, t_stack *stack_b)
// {
		// push le min 
		// push le deuxieme min 
		// sort 3 
// }

void  small_sort (t_stack *stack_a, t_stack *stack_b)
{
	stack_a->mini = nbr_mini(stack_a->stack, stack_a->count);
    stack_a->maxi = nbr_maxi(stack_a->stack, stack_a->count);
  if (!is_sorted(stack_a))
  {
    if (stack_a->count == 2)
        swap_a(stack_a->stack);
    else if ( stack_a->count == 3)
        sort_3(stack_a);
    else if (stack_a->count  == 4)
        sort_4(stack_a, stack_b);
    // else if (stack_a->count == 5)
    //     sort_5(stack_a, stack_b);
  }
}
