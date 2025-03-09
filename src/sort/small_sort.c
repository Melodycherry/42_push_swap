/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:41:03 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/07 17:25:50 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void move_min_to_top(t_stack *stack_a)
{
    if (stack_a->min_index <= (stack_a->count_stck / 2))
    {
        while (stack_a->stack[0] != stack_a->mini)
            rotate_a(stack_a);
    }
    else 
    {
        while (stack_a->stack[0] != stack_a->mini)
            reverse_rotate_a(stack_a);
    }
}

void sort_3(t_stack *stack_a)
{
	if (stack_a->stack[0] == stack_a->mini && stack_a->stack[1] == stack_a->maxi)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (stack_a->stack[1] == stack_a->maxi && stack_a->stack[2] == stack_a->mini)
		reverse_rotate_a(stack_a);
	else if (stack_a->stack[1] == stack_a->mini && stack_a->stack[2] == stack_a->maxi)
		swap_a(stack_a);
	else if (stack_a->stack[0] == stack_a->maxi && stack_a->stack[1] == stack_a->mini)
		rotate_a(stack_a);
	else if (stack_a->stack[0] == stack_a->maxi && stack_a->stack[2] == stack_a->mini)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
}

void sort_4(t_stack *stack_a, t_stack *stack_b)
{
	move_min_to_top(stack_a);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}


void sort_5(t_stack *stack_a, t_stack *stack_b)
{
	nbr_mini_index(stack_a);
	move_min_to_top(stack_a);
	push_b(stack_a, stack_b);
	nbr_mini_index(stack_a);
	move_min_to_top(stack_a);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void  small_sort (t_stack *stack_a, t_stack *stack_b)
{
	stack_a->mini = nbr_mini(stack_a);
	stack_a->maxi = nbr_maxi(stack_a);
  	if (!is_sorted(stack_a))
	{
		if (stack_a->count_gen == 2)
			swap_a(stack_a);
		else if ( stack_a->count_gen == 3)
			sort_3(stack_a);
		else if (stack_a->count_gen  == 4)
			sort_4(stack_a, stack_b);
		else if (stack_a->count_gen == 5)
		    sort_5(stack_a, stack_b);
	}
}
