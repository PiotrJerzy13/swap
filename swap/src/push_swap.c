/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:47 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 16:42:04 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_length(*a);
	while (len_a-- > 3)
		pb(a, b);
}

void	transfer_nodes(t_stack_node **a, t_stack_node **b)
{
	while (*b != NULL)
	{
		calibrate_nodes(*a, *b);
		transfer_optimal_node(a, b);
	}
}

void	rotate_to_smallest(t_stack_node **a)
{
	t_stack_node	*smallest;

	smallest = return_smallest(*a);
	if (smallest->median)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	split_stack(a, b);
	sort_three(a);
	transfer_nodes(a, b);
	choose_stack(*a);
	rotate_to_smallest(a);
}

void	calibrate_nodes(t_stack_node *a, t_stack_node *b)
{
	choose_stack(a);
	choose_stack(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
