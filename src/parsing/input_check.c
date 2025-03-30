/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:49:00 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/30 16:06:28 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

static int	parse_arg(char *p_arg, int *count);

int	input_check(int argc, char *argv[], int *count)
{
	int		i;
	char	*p_arg;

	i = 1; // pour ignorer le nom du programme 
	while (i < argc) // pour parcourir tous les arguments 
	{
		if (!argv[i][0]) // verif si valide 
			return (1);
		p_arg = argv[i]; // stock argument dans pointeur argument
		if (parse_arg(p_arg, count) == 1)
			return (1);
		i++; // check l'argument suivant 
	}
	return (0);
}

static int	parse_arg(char *p_arg, int *count)
{
	int	i;

	i = 0;
	while (p_arg[i]) // check caractere par caractere
	{
		if (!ft_isdigit(p_arg[i]) && !ft_isspace(p_arg[i])
			&& p_arg[i] != '-' && p_arg[i] != '+') // verif si chiffre, esp, signe
			return (1);
		while (ft_isspace(p_arg[i])) // ignore espace 
			i++;
		if (p_arg[i] == '+' || p_arg[i] == '-') // gestion du signe 
		{
			if (!ft_isdigit(p_arg[i + 1])) // verif qu'apres signe il y a un digit 
				return (1);
			i++;
		}
		while (ft_isdigit(p_arg[i]))
			i++;
		(*count)++; // incremente compteur de nombre trouvés 
	}
	if (p_arg[i - 1] == ' ') // si chaine termine par esp on corrige le compteru 
		(*count)--;
	return (0); // ok argument valide 
}

int	check_double(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->count_gen) // parcours chaque element du tableau 
	{
		j = i + 1; // compare avec element suivant 
		while (j < stack_a->count_gen)
		{
			if (stack_a->stack[i] == stack_a->stack[j]) // verif si doublon 
				return (1);
			j++;
		}
		i++;
	}
	return (0); // aucun doublon trouvé
}
