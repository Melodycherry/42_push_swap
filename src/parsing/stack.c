/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:09 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/30 16:05:15 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

int	init_stack(t_stack *stack_a, t_stack *stack_b, int count)
{	// alloc dynamique des stack, initialisation a zero 
	stack_a->stack = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack = (int *) ft_calloc(count, sizeof(int));
	stack_a->stack_radix = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack_radix = (int *) ft_calloc(count, sizeof(int));
	stack_a->stack_sort = (int *) ft_calloc(count, sizeof(int));
	stack_b->stack_sort = (int *) ft_calloc(count, sizeof(int));
	if (!stack_a->stack || !stack_b->stack // verif si allocation a echoué
		|| !stack_a->stack_radix || !stack_b->stack_radix
		|| !stack_a->stack_sort)
		return (1);
	// initialisation des compteurs de taille de piles 
	stack_a->count_gen = count;
	stack_b->count_gen = count;
	stack_a->count_stck = count;
	stack_b->count_stck = 0;
	// Initialisation des valeurs minimales et maximales
	stack_a->maxi = 0;
	stack_b->maxi = 0;
	stack_a->mini = 0;
	stack_b->mini = 0;
	// Initialisation des indices des éléments minimums
	stack_a->min_index = 0;
	stack_b->min_index = 0;
	return (0);
}

int	extract_arg(int argc, char *argv[], int *stack_a)
{
	char	*p_arg;
	int		i;
	int		j;

	i = 1; // ignore nom du programme
	j = 0; //index pour remplir stack a
	while (i < argc)
	{
		if (!argv[i][0])
			return (1);
		p_arg = argv[i]; // stock arg actuel
		if (insert_to_stack(p_arg, stack_a, &j) == 1) // insert dans stack
			return (1);
		i++; // passe a l'argument suivant 
	}
	return (0);
}

char	*extract_number(char *p_arg, int *i, int *is_neg)
{
	char	*num;
	char	*dup;

	num = NULL;
	*is_neg = 0;
	while (ft_isspace(p_arg[*i])) // ignore les espaces 
		(*i)++;
	if (p_arg[*i] == '+' || p_arg[*i] == '-') // verif du signe 
	{
		if (p_arg[*i] == '-')
		{
			*is_neg = 1; // marque le nombre comme negatif
			num = p_arg + *i; // positionne num sur le signe 
		}
		(*i)++;
	}
	// Si aucun signe négatif n'a été détecté, positionne num sur le premier chiffre
	if (!(*is_neg))
		num = p_arg + *i;
	// Parcours les chiffres du nombre
	while (ft_isdigit(p_arg[*i]))
		(*i)++;
	// Copie la portion de la chaîne contenant le nombre
	dup = ft_strndup(num, p_arg + *i - num);
	return (dup); // retourne la chaine du nombre extrait 
}

int	insert_to_stack(char *p_arg, int *stack_a, int *j)
{
	int		i;
	int		is_neg;
	char	*num;
	long	temp;

	i = 0;
	temp = 0;
	num = NULL;
	while (p_arg[i])
	{
		num = NULL;
		num = extract_number(p_arg, &i, &is_neg); // extrait le nombre
		if (!num)
			return (1);
		if (!num[0]) // si chaine est vide on arrete 
			break ;
		temp = ft_atol(num); // converti chaine en un long 
		free(num); // libere la memoire allouée
		if ((temp > INT_MAX) || (temp < INT_MIN))
			return (1);
		stack_a[*j] = (int)temp; // stock dans stack a
		(*j)++; // incremente index d'insertion 
	}
	return (0);
}
