/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:43 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/23 17:55:42 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	new_node->value = value;
	new_node->fwd = NULL;
	new_node->bwd = NULL;
	return (new_node);
}
