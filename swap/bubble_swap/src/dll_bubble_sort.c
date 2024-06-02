/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:29:27 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/26 21:20:21 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	dll_bubble_sort(t_stack_node **a)
{
	bool	swapped;
	int		length;
	int		i;
	int		j;

	length = stack_length(*a);
	i = 0;
	while (i < length - 1)
	{
		swapped = false;
		j = 0;
		while (j < length - i - 1)
		{
			if ((*a)->value > (*a)->fwd->value)
			{
				sa(a);
				printf("sa\n");
				swapped = true;
			}
			ra(a);
			printf("ra\n");
			j++;
		}
		j = 0;
		while (j < length - i - 1)
		{
			rra(a);
			printf("rra\n");
			j++;
		}
		i++;
		if (!swapped)
			break ;
	}
}
