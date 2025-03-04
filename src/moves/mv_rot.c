/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/04 22:41:36 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate(t_stack *stack)
{
	int first = stack->stack[0];
	int i = 0;

	while ( i < stack->count_stck)
	{
		stack->stack[i] = stack->stack[i+ 1];
		i++;	
	}
	stack->stack[i - 1] = first;
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}