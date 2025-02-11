/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:53:47 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/11 18:34:32 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Library

// Fonctions 
void	ft_error(char *s, int fd);
int		input_check(int argc, char *argv[], int *count);

void 	extract_arg(int argc, char *argv[], int *stack_a);
void	init_stack(int **stack_a, int **stack_b, int *count);
void	insert_to_stack(char *p_arg, int *stack_a, int j);

#endif