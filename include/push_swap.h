/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:53:47 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/02 19:11:32 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Library
#include <limits.h>

// Structures
typedef struct s_stack
{
	int *stack;
	int count;
	int mini;
	int maxi;
}	t_stack;

// typedef struct s_stacks
// {
// 	t_stack stack_a;
// 	t_stack stack_b;
// } t_stacks;

// Fonctions 
int		ft_error(void);
long	ft_atol(const char *str);
int		nbr_mini(int	*stack, int count);
int		nbr_maxi(int	*stack, int count);

// Parsing
int		input_check(int argc, char *argv[], int *count);
int 	extract_arg(int argc, char *argv[], int *stack_a);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int count);
int		insert_to_stack(char *p_arg, int *stack_a, int *j);
int		check_double(t_stack *stack_a);

//moves
void	swap_a(int	*stack_a);
void	swap_b(int *stack_b);
void	rotate_a(int *stack_a, int *count);
void	rotate_b(int *stack_b, int *count);
void	reverse_rotate_a(int *stack_a, int *count);
void	reverse_rotate_b(int *stack_b, int *count);
void	swap_ss(int *stack_a, int *stack_b);
void	rotate_rr(int *stack_a, int *stack_b, int *count);
void	reverse_rrr(int *stack_a, int *stack_b, int *count); 
void	push_a(int *stack_a, int *stack_b, int *count);
void	push_b(int *stack_a, int *stack_b, int *count);

//sorting
int 	is_sorted(t_stack *stack_a);
//void  	small_sort(t_stack *stack_a);
void  small_sort(t_stack *stack_a, t_stack *stack_b);

#endif
