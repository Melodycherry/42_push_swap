/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_combined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:01 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/23 17:17:08 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_ss(int *stack_a, int *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putendl_fd("ss", 1);
}

void	rotate_rr(int *stack_a, int *stack_b, int *count)
{
	rotate_a(stack_a, count);
	rotate_b(stack_b, count);
	ft_putendl_fd("rr", 1);
}

void	reverse_rrr(int *stack_a, int *stack_b, int *count)
{
	reverse_rotate_a(stack_a, count);
	reverse_rotate_b(stack_b, count);
	ft_putendl_fd("rrr", 1);
}