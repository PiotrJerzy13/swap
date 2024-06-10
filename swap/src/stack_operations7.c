/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:39:48 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/09 18:03:31 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->fwd;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char **argv, int argc)
{
	if (a && *a)
		free_stack(a);
	if (argc == 2 && argv)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
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
	t_stack_node	*tmp;

	if (!*head || !(*head)->fwd)
		return ;
	tmp = *head;
	*head = tmp->fwd;
	(*head)->bwd = NULL;
	tmp->fwd = (*head)->fwd;
	tmp->bwd = *head;
	(*head)->fwd = tmp;
	if (tmp->fwd)
		tmp->fwd->bwd = tmp;
}
