/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:36:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 16:50:35 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void free_stack(t_stack *stack)
{
	if (stack->stack)
		free(stack->stack);
	if (stack->stack_sort)
		free(stack->stack_sort);
	if (stack->stack_radix)
		free(stack->stack_radix);
}

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
