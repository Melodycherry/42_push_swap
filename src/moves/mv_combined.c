/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_combined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:01 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/13 16:55:49 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_ss(int *stack_a, int *stack_b) // sa + sb 
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putendl_fd("sa", 1);
	ft_putendl_fd("sb", 1);
}

void	rotate_rr(int *stack_a, int *stack_b) // ra + rb
{
	rotate_a(stack_a, count);
	rotate_b(stack_b, count);
	ft_putendl_fd("ra", 1);
	ft_putendl_fd("rb", 1);
}

void	reverse_rrr(int *stack_a, int *stack_b, int *count) // rra + rrb
{
	reverse_rotate_a(stack_a, count);
	reverse_rotate_b(stack_b, count);
	ft_putendl_fd("rra", 1);
	ft_putendl_fd("rrb", 1);
}