/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/08 17:45:40 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

int	parse_arg(char *p_arg, int *count);
void	ft_error(char *s, int fd);
void extract_to_stack(char *p_arg, int **stack,  int *count);

int	main (int argc, char *argv[])
{
	int i;
	char	*p_arg;
	int count;
	int *stack_a; // TRY

	if (argc < 2)
	{
		ft_error("Error argument", 2);
		return (1);
	}
	count = 0;
	i = 1;
	stack_a = 0;
	while (i < argc)
	{
		p_arg = argv[i];
		i++;
		if (parse_arg(p_arg, &count) == 1)
			return (1);
		else
		{
			extract_to_stack(p_arg, &stack_a, &count);
		}
	}
	i = 0;
	while (i < count) // test pour print la stack 
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);
	printf("count :%d\n", count);
	return (0);
}

int	parse_arg(char *p_arg, int *count)
{
	int i;
	
	i = 0;
	while (p_arg[i])
	{
		if (!ft_isdigit(p_arg[i]) && !ft_isspace(p_arg[i]) && p_arg[i] != '-' && p_arg[i] != '+')
		{
			ft_error("Error input", 2);
			return (1);
		}
		while (ft_isspace(p_arg[i]))
			i++;
		if (p_arg[i] == '+' || p_arg[i] == '-')
			i++;
		while (ft_isdigit(p_arg[i]))
			i++;
		(*count)++;
	}
	printf("count :%d\n", *count);
	return (0);
}

void extract_to_stack(char *p_arg, int **stack_a, int *count)
{
	int i;
	
	i = 0;
	*stack_a= malloc(sizeof(int) * (*count));
	if (!*stack_a)
		return;
	while (p_arg[i])   // pas correct 
	{
		(*stack_a)[i] = atoi(&p_arg[i]);
		i++;
	}
}

// a mettre dans utils ? 
void	ft_error(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}