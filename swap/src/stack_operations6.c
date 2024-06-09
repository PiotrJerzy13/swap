/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:45:52 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 15:33:27 by piotrwojnar      ###   ########.fr       */
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
	t_nodes			nodes;

	cheapest = return_cheapest(*b);
	nodes.cheap = cheapest;
	nodes.node = cheapest->target_node;
	align(a, b, &nodes);
	align_stack_a(a, cheapest->target_node);
	pa(a, b);
}
