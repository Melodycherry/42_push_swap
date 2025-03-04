/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:53:47 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/04 20:03:49 by mlaffita         ###   ########.fr       */
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
	int count_gen;
	int	count_stck;
	int mini;
	int maxi;
	int min_index;
}	t_stack;

// Fonctions 
int		ft_error(void);
int		nbr_mini(t_stack *stack);
int		nbr_maxi(t_stack *stack);
void 	nbr_mini_index(t_stack *stack);
int 	is_sorted(t_stack *stack_a);

// Parsing
int		input_check(int argc, char *argv[], int *count);
int 	extract_arg(int argc, char *argv[], int *stack_a);
char	*extract_number(char *p_arg, int *i, int *is_neg);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int count);
int		insert_to_stack(char *p_arg, int *stack_a, int *j);
int		check_double(t_stack *stack_a);

//moves
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	rotate(t_stack *stack);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	rotate_rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rrr(t_stack *stack_a, t_stack *stack_b);
void	update_mini_maxi(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

//sorting
void 	move_min_to_top(t_stack *stack_a);
void 	sort_3(t_stack *stack_a);
void 	sort_4(t_stack *stack_a, t_stack *stack_b);
void 	sort_5(t_stack *stack_a, t_stack *stack_b);
void  	small_sort(t_stack *stack_a, t_stack *stack_b);

#endif
