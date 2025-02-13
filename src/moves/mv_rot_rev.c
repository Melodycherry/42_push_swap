/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rot_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:38 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_a(int *stack_a, int *count) // decale d'une position vers le haut la pile a
{
	int temp;
	int first = stack_a[0];
	int i = 0;

	while ( i < count) // verif avec le count
	{
		stack_a[i] = stack_a[i+ 1];
		i++;	
	}
	stack_a[i - 1] = first;
	ft_putendl_fd("ra", 1);
}

void	rotate_b(int *stack_b, int *count) // decale d'une position vers le haut la pile b
{
	int temp;
	int first = stack_b[0];
	int i = 0;

	while ( i < count) // verif avec le count
	{
		stack_b[i] = stack_b[i+ 1];
		i++;	
	}
	stack_b[i - 1] = first;
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate_a(int *stack_a, int *count)
{
	int temp;
	int i = count;
	int last = stack_a[i - 1];

	while ( i > 0) // verif count
	{
		stack_a[i] = stack_a[i - 1];
		i--;	
	}
	stack_a[i] = last;
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(int *stack_b, int *count)
{
	int temp;
	int i = count;
	int last = stack_b[i - 1];

	while ( i > 0) // verif count
	{
		stack_b[i] = stack_b[i - 1];
		i--;	
	}
	stack_b[i] = last;
	ft_putendl_fd("rrb", 1);
}