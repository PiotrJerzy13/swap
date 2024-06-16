/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:39:48 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/15 21:43:16 by piotrwojnar      ###   ########.fr       */
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
