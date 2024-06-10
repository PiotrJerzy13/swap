/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:32:10 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 16:39:30 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_price(t_stack_node *node, int len)
{
	if (node->median)
		return (node->place);
	else
		return (len - node->place);
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(a);
	len_b = stack_length(b);
	while (b)
	{
		b->price = calculate_price(b, len_b);
		if (b->target_node)
			b->price += calculate_price(b->target_node, len_a);
		b = b->fwd;
	}
}

void	reset_cheapest_flags(t_stack_node *b)
{
	while (b != NULL)
	{
		b->target = false;
		b = b->fwd;
	}
}

t_stack_node	*find_cheapest_node(t_stack_node *b)
{
	t_stack_node	*cheapest_node;
	long			best_match_value;

	cheapest_node = NULL;
	best_match_value = LONG_MAX;
	while (b != NULL)
	{
		if (b->price < best_match_value)
		{
			best_match_value = b->price;
			cheapest_node = b;
		}
		b = b->fwd;
	}
	return (cheapest_node);
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	reset_cheapest_flags(b);
	cheapest_node = find_cheapest_node(b);
	if (cheapest_node)
		cheapest_node->target = true;
}
