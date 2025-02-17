/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:53:47 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/13 16:59:40 by mlaffita         ###   ########.fr       */
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

//move
void	swap_a(int	*stack_a);
void	swap_b(int *stack_b);
void	rotate_a(int *stack_a, int *count);
void	rotate_b(int *stack_b, int *count);
void	reverse_rotate_a(int *stack_a, int *count);
void	reverse_rotate_b(int *stack_b, int *count);
void	swap_ss(int *stack_a, int *stack_b);
void	rotate_rr(int *stack_a, int *stack_b);
void	reverse_rrr(int *stack_a, int *stack_b, int *count); 


#endif