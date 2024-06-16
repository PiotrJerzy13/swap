/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:39:48 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/16 18:49:44 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_stack_node **a, char **argv, int argc)
{
	if (a)
		release_stack(a);
	if (argc == 2 && argv)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_array(char **array)
{
	char	**current;

	if (!array)
		return ;
	current = array;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(array);
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!head || !*head || !(*head)->fwd)
		return ;
	first = *head;
	second = first->fwd;
	*head = second;
	first->fwd = second->fwd;
	if (second->fwd)
		second->fwd->bwd = first;
	second->fwd = first;
	second->bwd = NULL;
	first->bwd = second;
}

t_stack_node	*find_min_price_node(t_stack_node *head)
{
	t_stack_node	*min_node;
	long			min_price;

	min_node = NULL;
	min_price = LONG_MAX;
	while (head != NULL)
	{
		if (head->price < min_price)
		{
			min_price = head->price;
			min_node = head;
		}
		head = head->fwd;
	}
	return (min_node);
}
