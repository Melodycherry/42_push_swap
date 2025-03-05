/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/05 14:54:48 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putchar_fd('\n', 2);
	return(1);
}

int is_sorted(t_stack *stack_a)
{
	int i;

	i = 0;
	while ( i < stack_a->count_gen - 1)
	{
		if (stack_a->stack[i] > stack_a->stack[i + 1])
			return (0);
		i++;
	}
	return(1);
}

int nbr_mini(t_stack *stack)
{
	int i;
	int mini;

	i = 0;
	mini = stack->stack[i];
	while (i < stack->count_stck)
	{
		if(stack->stack[i] < mini)
			mini = stack->stack[i];
		i++;
	}
	return (mini);
}

int nbr_maxi(t_stack *stack)
{
	int i;
	int maxi;

	i = 0;
	maxi = stack->stack[i];
	while (i < stack->count_stck)
	{
		if (stack->stack[i] > maxi )
			maxi = stack->stack[i];
		i++;
	}
	return (maxi);
}

void nbr_mini_index(t_stack *stack)
{
    int i;
    
    i = 0;
    while (i < stack->count_stck)
    {
        if (stack->stack[i] == stack->mini)
			break;
        i++;
    }
	stack->min_index = i;
}