/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:23:46 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/16 18:24:11 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	get_min_value(t_stack_node *a)
{
	t_stack_node	*current;
	int				min;

	if (a == NULL)
		return (0);
	current = a;
	min = current->value;
	current = current->next;
	while (current)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_position_of_value(t_stack_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
