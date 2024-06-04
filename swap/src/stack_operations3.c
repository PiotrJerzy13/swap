/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:38:02 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/04 08:26:55 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*new_head;

	if (!*head || !(*head)->fwd)
		return ;
	last = *head;
	while (last->fwd)
		last = last->fwd;
	last->bwd->fwd = NULL;
	new_head = last;
	new_head->fwd = *head;
	new_head->bwd = NULL;
	(*head)->bwd = new_head;
	*head = new_head;
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