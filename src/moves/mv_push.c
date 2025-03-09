/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/09 17:30:19 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->count_stck;
	while (j > 0)
	{
		stack_a->stack[j] = stack_a->stack[j - 1];
		j--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	stack_a->count_stck++;
	stack_b->count_stck--;
	while (i < stack_b->count_stck)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	update_mini_maxi(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = stack_b->count_stck;
	while (j > 0)
	{
		stack_b->stack[j] = stack_b->stack[j - 1];
		j--;
	}
	stack_b->stack[0] = stack_a->stack[0];
	stack_b->count_stck++;
	stack_a->count_stck--;
	while (i < stack_a->count_stck)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	update_mini_maxi(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	push_a_big(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->count_stck;
	while (j > 0)
	{
		stack_a->stack_radix[j] = stack_a->stack_radix[j - 1];
		j--;
	}
	stack_a->stack_radix[0] = stack_b->stack_radix[0];
	stack_a->count_stck++;
	stack_b->count_stck--;
	while (i < stack_b->count_stck)
	{
		stack_b->stack_radix[i] = stack_b->stack_radix[i + 1];
		i++;
	}
	update_mini_maxi(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	push_b_big(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = stack_b->count_stck;
	while (j > 0)
	{
		stack_b->stack_radix[j] = stack_b->stack_radix[j - 1];
		j--;
	}
	stack_b->stack_radix[0] = stack_a->stack_radix[0];
	stack_b->count_stck++;
	stack_a->count_stck--;
	while (i < stack_a->count_stck)
	{
		stack_a->stack_radix[i] = stack_a->stack_radix[i + 1];
		i++;
	}
	update_mini_maxi(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	update_mini_maxi(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->mini = nbr_mini(stack_a);
	stack_a->maxi = nbr_maxi(stack_a);
	stack_b->mini = nbr_mini(stack_b);
	stack_b->maxi = nbr_maxi(stack_b);
}
