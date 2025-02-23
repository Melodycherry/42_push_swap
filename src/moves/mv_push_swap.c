/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/23 13:46:24 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_a(int	*stack_a) // interverti les 2 premiers elements au sommet de la pile a 
{
	// condition si 1 element ou zero element, ne fait rien 
	if (stack_a == NULL || stack_a[1] == '\0')
		return;
	int temp;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_putendl_fd("sa", 1);
}

void	swap_b(int *stack_b) // interverti les 2 premiers elements au sommet de la pile b
{
	// condition si 1 element ou zero element ne fait rien 
	if (stack_b == NULL || stack_b[1] == '\0')
		return;
	int temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_putendl_fd("sb", 1);
}

void	push_a(int *stack_a, int *stack_b) // prend le 1er elemen de b et le met sur a
{
	static int index_a;
	static int index_b;
	
	// si b est vide on ne fait rien 
	if (stack_b == NULL)
		return;
		
	// decale tt vers le bas pour laisser position 0 libre
	
	// mettre b sur le a 
	stack_a[0] = stack_b[0];

	//decale b vers le haut pour supprimer 1er element 
	
	ft_putendl_fd("pa", 1);
	//pa
}

void	push_b()
{
	ft_putendl_fd("pb", 1);
	//pb
}