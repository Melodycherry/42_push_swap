/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_combined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:01 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/07 17:24:24 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putendl_fd("ss", 1);
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putendl_fd("rr", 1);
}

void	reverse_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putendl_fd("rrr", 1);
}
