/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:55:10 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/01 22:14:25 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

static void	rotate(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->fwd)
		return ;
	first = *head;
	second = (*head)->fwd;
	*head = second;
	second->bwd = NULL;
	while (second->fwd)
		second = second->fwd;
	second->fwd = first;
	first->bwd = second;
	first->fwd = NULL;
}
void ft_stack_add_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node *temp;

	if (!lst || !new)
		return;
	if (!(*lst))
	{
		*lst = new;
		return;
	}
	temp = *lst;
	while (temp->fwd)
		temp = temp->fwd;
	temp->fwd = new;
	new->bwd = temp;
	new->fwd = NULL;
}

static void rotate(t_stack_node **head)
{
	t_stack_node *first;
	t_stack_node *second;

	if (!*head || !(*head)->fwd)
		return;
	first = *head;
	second = (*head)->fwd;
	*head = second;
	second->bwd = NULL;

	// Use ft_stack_add_back to add the old head to the end of the list
	ft_stack_add_back(head, first);
}

void ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
