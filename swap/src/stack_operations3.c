/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:38:02 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/16 13:27:04 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*second_to_last;

	if (!head || !(*head) || !(*head)->fwd)
		return ;
	last = *head;
	second_to_last = NULL;
	while (last->fwd)
	{
		second_to_last = last;
		last = last->fwd;
	}
	second_to_last->fwd = NULL;
	last->fwd = *head;
	last->bwd = NULL;
	(*head)->bwd = last;
	*head = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotation(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotation(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotation(a);
	reverse_rotation(b);
	write(1, "rrr\n", 4);
}

void	push_r(t_stack_node **stack, t_stack_node *cheap, char st_na)
{
	int	is_median;

	if (!stack || !*stack || !cheap)
		return ;
	is_median = cheap->median;
	while (*stack != cheap)
	{
		if (st_na == 'a')
		{
			if (is_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (st_na == 'b')
		{
			if (is_median)
				rb(stack);
			else
				rrb(stack);
		}
		else
			return ;
	}
}
