/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:49:10 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/23 17:57:34 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	error_nondigit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->fwd;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
