/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_chunked_push_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:18:02 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/15 20:38:19 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_chunk_size(int total)
{
	if (total <= 10)
		return (4);
	else if (total <= 100)
		return (total / 5);
	else
		return (total / 11);
}

int	has_elements_in_range(t_stack_node **stack, int min_index, int max_index)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (current->index >= min_index && current->index <= max_index)
			return (1);
		current = current->next;
	}
	return (0);
}

int	find_closest_from_top(t_stack_node **stack, int min_index, int max_index)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = (*stack);
	while (current)
	{
		if (current->index >= min_index && current->index <= max_index)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	find_closest_from_bottom(t_stack_node **stack, int min_index, int max_index)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = *stack;
	while (current && current->next)
		current = current->next;
	while (current)
	{
		if (current->index >= min_index && current->index <= max_index)
			return (i);
		current = current->prev;
		i++;
	}
	return (-1);
}

void	rotate_to_top_stack_a(t_stack_node **a, int min_index, int max_index)
{
	int	top_num_steps;
	int	bottom_num_steps;

	if (a == NULL || (*a) == NULL)
		return ;
	top_num_steps = find_closest_from_top(a, min_index, max_index);
	bottom_num_steps = find_closest_from_bottom(a, min_index, max_index);
	if (top_num_steps == -1 && bottom_num_steps == -1)
		return ;
	if (top_num_steps <= bottom_num_steps)
	{
		while (*a && !((*a)->index >= min_index && (*a)->index <= max_index))
			ra(a);
	}
	else
	{
		while (*a && !((*a)->index >= min_index && (*a)->index <= max_index))
			rra(a);
	}
}
