/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:41:28 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 17:27:57 by piotrwojnar      ###   ########.fr       */
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
		if (stack->node > biggest_node->node)
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

	first = (*a)->node;
	second = (*a)->fwd->node;
	third = (*a)->fwd->fwd->node;
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
	if (stack->node < smallest->node)
		smallest = stack;
	return (find_smallest(stack->fwd, smallest));
}

t_stack_node	*return_smallest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	return (find_smallest(stack, stack));
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->node = value;
	new_node->fwd = NULL;
	new_node->bwd = NULL;
	return (new_node);
}
