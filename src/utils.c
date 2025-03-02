/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:39 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/02 19:07:34 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_error(void) // modifie ok 
{
	ft_putstr_fd("Error\n", 2);
	ft_putchar_fd('\n', 2);
	return(1);
}

long	ft_atol(const char *str)
{
	int	i;
	int	signe;
	long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signe * result);
}

// Fonction pour trouver le minimum d'un tableau
int	nbr_mini(int *stack, int count)
{
	int i;
	int mini;
	
	i = 0;
	mini = stack[i];
	while ( i < count)
	{
		if (stack[i] < mini )
			mini = stack[i];
		i++;
	}
	return (mini);
}

// Fonction pour trouver le maximum d'un tableau
int nbr_maxi(int *stack, int count)
{
	int i;
	int maxi;

	i = 0;
	maxi = stack[i];
	while (i < count)
	{
		if (stack[i] > maxi )
			maxi = stack[i];
		i++;
	}
	return (maxi);
}