/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:48:21 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 13:45:28 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "libtft.h"

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
}	t_stack_node;

// Stack operations
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);

// Stack utilities
int				stack_length(t_stack_node *head);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **a, t_stack_node *new_node);

// Error handling
bool			handle_errors(t_stack_node **a, char *argv, long n);
void			free_errors(t_stack_node **a, char **argv, int argc);
int				error_nondigit(char *str);
int				error_duplicated(t_stack_node *a, long n);

// Node creation
t_stack_node	*create_node(int value);

// Sorting algorithms
int				process_values(t_stack_node **a, char **values, int i);
void			choose_stack(t_stack_node *stack);
int				init_stack_no_split(t_stack_node **a, int argc, char **argv);
void			sort_three(t_stack_node **a);
void			push_r(t_stack_node **stack, t_stack_node *cheap, char st_na);
void			push_stack(t_stack_node **dst, t_stack_node **src);

// Utility functions
char			**ft_split(char const *s, char c);
long			ft_atol(const char *str);
void			free_array(char **array);
t_stack_node	*return_biggest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_ordered(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest);
t_stack_node	*return_smallest(t_stack_node *stack);
void			split_stack(t_stack_node **a, t_stack_node **b);
void			transfer_nodes(t_stack_node **a, t_stack_node **b);
void			rotate_to_smallest(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
bool			stack_ordered(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				calculate_price(t_stack_node *node, int len);
void			set_price(t_stack_node *a, t_stack_node *b);
void			reset_cheapest_flags(t_stack_node *b);
t_stack_node	*find_cheapest_node(t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			align_stack_a(t_stack_node **a, t_stack_node *target_node);
void			align_stack_b(t_stack_node **b, t_stack_node *cheapest);
void			align(t_stack_node **a, t_stack_node **b, t_stack_node *cheap, t_stack_node *node);
void			transfer_optimal_node(t_stack_node **a, t_stack_node **b);

#endif // PUSH_SWAP_H
