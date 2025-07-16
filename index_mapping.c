/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:14:45 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/16 18:06:12 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mapping_indexes(t_stack_node **stack, int *sorted_arr)
{
	int				i;
	t_stack_node	*current;
	int				size;

	size = find_stack_size(*stack);
	current = (*stack);
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current-> value == sorted_arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	get_indexed_stack(t_stack_node **a)
{
	int	*sorted_array;

	if (a == NULL || (*a) == NULL)
		return ;
	sorted_array = quicksort(*a);
	if (!sorted_array)
		return ;
	mapping_indexes(a, sorted_array);
	free(sorted_array);
}
