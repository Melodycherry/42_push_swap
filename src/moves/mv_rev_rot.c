/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/07 17:24:34 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	reverse_rotate(t_stack *stack)
{
	int i = stack->count_stck - 1;
	int last = stack->stack[i];

	while ( i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;	
	}
	stack->stack[i] = last;
}

void	reverse_rotate_a(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}
