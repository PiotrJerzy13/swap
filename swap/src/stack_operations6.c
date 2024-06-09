/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:45:52 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 13:45:21 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack_a(t_stack_node **a, t_stack_node *target_node)
{
	while (*a != target_node)
	{
		if (target_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	align_stack_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	align(t_stack_node **a, t_stack_node **b, t_stack_node *cheap, t_stack_node *node)
{
	if (cheap->above_median && node->above_median)
	{
		while (*a != node && *b != cheap)
			rr(a, b);
	}
	else if (!cheap->above_median && !node->above_median)
	{
		while (*a != node && *b != cheap)
			rrr(a, b);
	}
}

void	transfer_optimal_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	align(a, b, cheapest, cheapest->target_node);
	align_stack_a(a, cheapest->target_node);
	pa(a, b);
}
