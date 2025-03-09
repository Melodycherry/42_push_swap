/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 17:35:53 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->stack == NULL || stack->stack[1] == '\0')
		return ;
	temp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
}

void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}
