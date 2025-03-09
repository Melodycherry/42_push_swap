/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 16:40:50 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate(t_stack *stack, t_bool is_small)
{
	int first;
	int i;

	i = 0;
	if (is_small)
	{
		first = stack->stack[0];
		while (i < stack->count_stck - 1)
		{
			stack->stack[i] = stack->stack[i+ 1];
			i++;	
		}
		stack->stack[i] = first;
	}
	else
	{
		first = stack->stack_radix[0];
		while (i < stack->count_stck - 1)
		{
			stack->stack_radix[i] = stack->stack_radix[i + 1];
			i++;	
		}
		stack->stack_radix[i] = first;
	}
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a, TRUE);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b, TRUE);
	ft_putendl_fd("rb", 1);
}
void	rotate_a_big(t_stack *stack_a)
{
	rotate(stack_a, FALSE);
	ft_putendl_fd("ra", 1);
}

void	rotate_b_big(t_stack *stack_b)
{
	rotate(stack_b, FALSE);
	ft_putendl_fd("rb", 1);
}
