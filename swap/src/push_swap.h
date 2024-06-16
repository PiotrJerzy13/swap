/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:48:21 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/16 18:23:18 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libtft/libft.h"

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
	int					node;
	int					place;
	int					price;
	bool				median;
	bool				target;
}	t_stack_node;

// Struct to hold nodes for alignment
typedef struct s_nodes
{
	t_stack_node	*cheap;
	t_stack_node	*node;
}	t_nodes;

// Sort_three functions
t_stack_node	*return_biggest(t_stack_node *stack);
void			sort_three(t_stack_node **a);
t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest);
t_stack_node	*return_smallest(t_stack_node *stack);
t_stack_node	*create_node(int value);

// Error handling
bool			validate_input(t_stack_node **stack, char *arg, long num);
int				has_nondigit(char *str);
int				has_duplicate_value(t_stack_node *stack, long num);
void			release_stack(t_stack_node **stack_ptr);
bool			handle_errors(t_stack_node **stack, char *arg_array, long n);

// main functions
int				process_values(t_stack_node **a, char **values, int i);
int				initialize_stack_single(t_stack_node **a, char *input);
int				initialize_stack(t_stack_node **a, int argc, char **argv);
void			calculate_price_node(t_stack_node *node, int len_a, int len_b);

// push_swap functions
void			split_stack(t_stack_node **a, t_stack_node **b);
void			transfer_nodes(t_stack_node **a, t_stack_node **b);
void			rotate_to_smallest(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			calibrate_nodes(t_stack_node *a, t_stack_node *b);

// Stack operations 1
void			ft_stack_add_back(t_stack_node **lst, t_stack_node *new);
void			rotate(t_stack_node **head);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// Stack operations 2
void			append_node(t_stack_node **a, t_stack_node *new_node);
int				init_stack_no_split(t_stack_node **a, int argc, char **argv);
long			ft_atol(const char *str);
void			choose_stack(t_stack_node *stack);
int				stack_length(t_stack_node *head);

// Stack operations 3
void			reverse_rotation(t_stack_node **head);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			push_r(t_stack_node **stack, t_stack_node *cheap, char st_na);

// Stack operations 4
void			push_stack(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
bool			stack_ordered(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);

// Stack operations 5
int				calculate_price(t_stack_node *node, int len);
void			set_price(t_stack_node *a, t_stack_node *b);
void			reset_cheapest_flags(t_stack_node *b);
t_stack_node	*find_cheapest_node(t_stack_node *b);
void			set_cheapest(t_stack_node *b);

// Stack operations 6
void			align_stack_a(t_stack_node **a, t_stack_node *target_node);
void			align_stack_b(t_stack_node **b, t_stack_node *cheapest);
void			align(t_stack_node **a, t_stack_node **b, t_nodes *nodes);
void			transfer_optimal_node(t_stack_node **a, t_stack_node **b);
void			set_target_node(t_stack_node *a, t_stack_node *b);

// Stack operations 7
void			sa(t_stack_node **a);
void			swap(t_stack_node **head);
void			free_errors(t_stack_node **a, char **argv, int argc);
void			free_array(char **array);
t_stack_node	*find_min_price_node(t_stack_node *head);

#endif // PUSH_SWAP_H
