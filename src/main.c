/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/09 20:38:18 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

int	parse_arg(char *p_arg, int *count);
void extract_to_stack(int argc, char *argv[], int **stack_a);
void	init_stack(int **stack_a, int **stack_b, int *count);
void	insert_to_stack(char *p_arg, int **stack_a);

int	main (int argc, char *argv[])
{
	int count;
	int *stack_a;
	int *stack_b;

	if (argc < 2)
	{
		ft_error("Error argument", 2);
		return (1);
	}
	count = 0;
	if (input_check(argc, argv, &count)  == 1)
	{
		ft_error("Error input", 2);
		return (1);
	}
	init_stack(&stack_a, &stack_b, &count);
	extract_to_stack(argc, argv, &stack_a);
	
	free(stack_a);
	printf("count :%d\n", count);
	return (0);
}

void	init_stack(int **stack_a, int **stack_b, int *count)
{
	*stack_a = (int *) ft_calloc(*count, sizeof(int));
	*stack_b = (int *) ft_calloc(*count, sizeof(int));
}



void extract_to_stack(int argc, char *argv[], int **stack_a)
{
	char	*p_arg;
	int i;
	
	i = 1;
	while (i < argc)
	{
		p_arg = argv[i];
		
		i++;
		insert_to_stack(p_arg, stack_a);
	}
}

void	insert_to_stack(char *p_arg, int **stack_a)
{
	int i;
	int j;
	int	is_neg;
	(void)stack_a;
	
	i = 0;
	is_neg = 0;
	while (p_arg[i])
		{
			while (ft_isspace(p_arg[i]))
				i++;
			if (p_arg[i] == '+' || p_arg[i] == '-')
			{
				if (p_arg[i] == '-')
				{
					is_neg = 1;
					j = 0; // debut 
				}
				i++;
			}
			if (!is_neg)
				j = 0;
			(void)j;
			while (ft_isdigit(p_arg[i]))
				i++;
			// exporter le num
		}
}