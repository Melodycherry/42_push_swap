/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/13 16:43:52 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_a(int	*stack_a) // interverti les 2 premiers elements au sommet de la pile a 
{
	// rajouter condition si 1 element ou zero element ne fait rien 
	int temp;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_putendl_fd("sa", 1);
}

void	swap_b(int *stack_b) // interverti les 2 premiers elements au sommet de la pile b
{
	// rajouter condition si 1 element ou zero element ne fait rien 
	int temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_putendl_fd("sb", 1);
}

void	push_a()
{
	ft_putendl_fd("pa", 1);
	//pa
}

void	push_b()
{
	ft_putendl_fd("pb", 1);
	//pb
}