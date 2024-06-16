/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:45:52 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/15 20:03:08 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack_a(t_stack_node **a, t_stack_node *target_node)
{
	while (*a != target_node)
	{
		if (target_node->median)
			ra(a);
		else
			rra(a);
	}
}

void	align_stack_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->median)
			rb(b);
		else
			rrb(b);
	}
}

void	align(t_stack_node **a, t_stack_node **b, t_nodes *nodes)
{
	if (nodes->cheap->median && nodes->node->median)
	{
		while (*a != nodes->node && *b != nodes->cheap)
			rr(a, b);
	}
	else if (!nodes->cheap->median && !nodes->node->median)
	{
		while (*a != nodes->node && *b != nodes->cheap)
			rrr(a, b);
	}
}

void	transfer_optimal_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->median && cheapest->target_node->median)
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rr(a, b);
	}
	else if (!cheapest->median && !cheapest->target_node->median)
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rrr(a, b);
	}
	push_r(b, cheapest, 'b');
	push_r(a, cheapest->target_node, 'a');
	pa(a, b);
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*smallest_node;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	smallest_node = return_smallest(a);
	while (b)
	{
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->node > b->node)
			{
				if (!target_node || current_a->node < target_node->node)
				{
					target_node = current_a;
				}
			}
			current_a = current_a->fwd;
		}
		if (!target_node)
			target_node = smallest_node;
		b->target_node = target_node;
		b = b->fwd;
	}
}
