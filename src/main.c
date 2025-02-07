/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/07 16:50:02 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include "push_swap.h"

int	parse_arg(char *p_arg, int *count);
void	ft_error(char *s, int fd);
int extract_to_stack(char *p_arg, int *stack, int *count);

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
	while (i < argc)
	{
		p_arg = argv[i];
		i++;
		//printf("main: %s\n", p_arg);
		if (parse_arg(p_arg, &count) == 1)
			return (1); // indique une erreur 
		else
			extract_to_stack(p_arg, &stack_a, &count);
	}
	//printf("count :%d\n", count);
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
		printf("parse: %s\n", p_arg);
	}
	printf("count :%d\n", *count);
	return (0);
}

int extract_to_stack(char *p_arg, int *stack, int *count)
{
	
}

// a mettre dans utils ? 
void	ft_error(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}