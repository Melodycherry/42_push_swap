/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/26 17:37:30 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_a(int	*stack_a)
{
	if (stack_a == NULL || stack_a[1] == '\0')
		return;
	int temp;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_putendl_fd("sa", 1);
}

void	swap_b(int *stack_b)
{
	if (stack_b == NULL || stack_b[1] == '\0')
		return;
	int temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_putendl_fd("sb", 1);
}

void	push_a(int *stack_a, int *stack_b, int *count)
{
	int i = 0;
	int j = *count;
	while (j > 0)
	{
		stack_a[j] = stack_a[j - 1];
		j--;
	}
	stack_a[0] = stack_b[0];
	while ( i < *count)
	{
		stack_b[i] = stack_b[i + 1];
		i++;	
	}
	ft_putendl_fd("pa", 1);
}

void	push_b(int *stack_a, int *stack_b, int *count)
{
	int i = 0;
	int j = *count;
	while (j > 0)
	{
		stack_b[j] = stack_b[j - 1];
		j--;
	}
	stack_b[0] = stack_a[0];
	while ( i < *count)
	{
		stack_a[i] = stack_a[i + 1];
		i++;	
	}
	ft_putendl_fd("pb", 1);
}