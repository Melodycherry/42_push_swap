/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:17 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/05 21:04:38 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"

int	parse_arg(char *p_arg);

int	main (int argc, char *argv[])
{
	int i;
	char	*p_arg;

	if (argc < 2)
	{
		//error
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		p_arg = argv[i];
		i++;
		printf("main: %s\n", p_arg);
		if (parse_arg(p_arg) == 1)
			return (1);
	}
}

int	parse_arg(char *p_arg)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (p_arg[i])
	{
		if (!ft_isdigit(p_arg[i]) && !ft_isspace(p_arg[i]) && p_arg[i] != '-' && p_arg[i] != '+')
		{
			//error
			printf("error\n");
			return (1);
		}
		while (ft_isspace(p_arg[i]))
			i++;
		while (ft_isdigit(p_arg[i]))
			i++;
		// trouver comment count 
		printf("parse: %s\n", p_arg + i);
		i++;
	}
	return (0);
}