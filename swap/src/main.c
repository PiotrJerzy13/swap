/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:57:36 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/06/15 23:02:31 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	process_values(t_stack_node **a, char **values, int i)
{
	t_stack_node	*new_node;
	long			val;

	while (values[i])
	{
		val = ft_atol(values[i]);
		if (!handle_errors(a, values[i], val))
		{
			free_errors(a, values, i);
			return (0);
		}
		new_node = create_node(val);
		if (!new_node)
		{
			free_errors(a, values, i);
			return (0);
		}
		if (!(*a))
			*a = new_node;
		else
			append_node(a, new_node);
		i++;
	}
	return (1);
}

int	initialize_stack_single(t_stack_node **a, char *input)
{
	char	**values;
	int		result;

	values = ft_split(input, ' ');
	if (values == NULL)
	{
		free_errors(a, values, 0);
		return (0);
	}
	result = process_values(a, values, 0);
	free_array(values);
	return (result);
}

int	initialize_stack(t_stack_node **a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!initialize_stack_single(a, argv[1]))
			return (0);
	}
	else
	{
		if (!init_stack_no_split(a, argc, argv))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (!initialize_stack(&a, argc, argv))
		return (1);
	if (stack_ordered(a))
	{
		release_stack(&a);
		return (0);
	}
	len = stack_length(a);
	if (len == 3)
		sort_three(&a);
	else
		push_swap(&a, &b);
	release_stack(&a);
	release_stack(&b);
	return (0);
}
