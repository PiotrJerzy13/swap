/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:29:27 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/23 18:06:29 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	dll_bubble_sort(t_stack_node **rootp)
{
	int				swapped;
	t_stack_node	**current;

	if (!rootp || !*rootp)
		return ;
	do {
		swapped = 0;
	current = rootp;
	while ((*current)->fwd != NULL)
	{
		if ((*current)->value > (*current)->fwd->value)
		{
			dll_swap(current);
			swapped = 1;
		}
		current = &(*current)->fwd;
	}
}
while (swapped);
}
