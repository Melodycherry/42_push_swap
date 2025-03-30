/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:40:57 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/30 17:42:45 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(t_stack *stack_a)
{
	int		i;
	int		j;
	t_bool	swapped;

	i = 0;
	// Boucle principale pour parcourir toute la pile
	while (i < stack_a->count_gen)
	{
		swapped = FALSE; // Indicateur pour vérifier si un échange a eu lieu
		j = 0;
		while (j < (stack_a->count_gen - i - 1))
		{
			// Si l'élément courant est plus grand que le suivant, on les échange
			if (stack_a->stack_sort[j] > stack_a->stack_sort[j + 1])
			{
				swap(&stack_a->stack_sort[j], &stack_a->stack_sort[j + 1]);
				swapped = TRUE; 
			}
			j++;
		}
		// Si aucun échange n'a eu lieu, la pile est déjà triée
		if (swapped == FALSE)
			break ; // Sort de la boucle principale, le tri est terminé
		i++;
	}
}

void	fill_stack_radix(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	// Parcours chaque élément de la pile `stack_a`
	while (i < stack_a->count_gen)
	{
		j = 0;
		// Compare l'élément courant de `stack_a` avec chaque élément de `stack_sort`
		while (j < stack_a->count_gen)
		{
			// Si les éléments correspondent, on place l'index de tri dans `stack_radix`
			if (stack_a->stack[i] == stack_a->stack_sort[j])
			{
				stack_a->stack_radix[i] = j; // L'index de tri est assigné à `stack_radix[i]
			}
			j++;
		}
		i++;
	}
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	max_index = stack_a->count_gen - 1;
	max_bit = 0;
	// Calcul du nombre de bits nécessaires pour représenter `max_index`
	while ((max_index >> max_bit) != 0)
		++max_bit;
	// Boucle pour chaque bit, de 0 jusqu'au bit le plus significatif
	while (i < max_bit)
	{
		j = 0;
		// Boucle pour chaque élément de `stack_a` (les éléments seront déplacés entre `stack_a` et `stack_b`)
		while (j < stack_a->count_gen)
		{
			// Vérifie si le bit `i` de `stack_a->stack_radix[j]` est égal à 1
			// Si c'est le cas, on effectue une rotation sur `stack_a`, sinon on déplace l'élément dans `stack_b`
			if (((stack_a->stack_radix[0] >> i) & 1) == 1)
				rotate_a_big(stack_a); // Déplace l'élément vers le haut dans `stack_a`
			else
				push_b_big(stack_a, stack_b); // Déplace l'élément dans `stack_b`
			j++;
		}
		// Déplace tous les éléments de `stack_b` vers `stack_a` (puisque les éléments sont déplacés en fonction des bits)
		while (stack_b->count_stck != 0)
			push_a_big(stack_a, stack_b); // Remet les éléments dans `stack_a`
		i++; // Passe au bit suivant
	}
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_memcpy(stack_a->stack_sort, stack_a->stack,
		(stack_a->count_gen * sizeof(int)));
	bubble_sort(stack_a);
	fill_stack_radix(stack_a);
	radix(stack_a, stack_b);
}
