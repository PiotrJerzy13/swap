/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:41:28 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 12:27:53 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*return_biggest(t_stack_node *stack)
{
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_node = stack;
	while (stack != NULL)
	{
		if (stack->value > biggest_node->value)
		{
			biggest_node = stack;
		}
		stack = stack->fwd;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;	
	int	third;

	first = (*a)->value;
	second = (*a)->fwd->value;
	third = (*a)->fwd->fwd->value;
	if (first > second && second > third)
	{
		ra(a);
		sa(a);
	}
	else if (first > third && third > second)
		ra(a);
	else if (second > first && first > third)
		sa(a);
	else if (second > third && third > first)
		rra(a);
	else if (third > first && first > second)
	{
		sa(a);
		ra(a);
	}
}

t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest)
{
	if (!stack)
		return (smallest);
	if (stack->value < smallest->value)
		smallest = stack;
	return (find_smallest(stack->fwd, smallest));
}

t_stack_node	*return_smallest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	return (find_smallest(stack, stack));
}
