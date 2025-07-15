/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:57:29 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/14 13:07:32 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot(int *arr, int pivot_index, int end_index)
{
	int	swap_index;
	int	i;
	int	temp;

	if (pivot_index >= end_index)
		return (pivot_index);
	swap_index = pivot_index;
	i = pivot_index + 1;
	while (i <= end_index)
	{
		if (arr[i] < arr[pivot_index])
		{
			swap_index++;
			temp = arr[swap_index];
			arr[swap_index] = arr[i];
			arr[i] = temp;
		}
		i++;
	}
	temp = arr[swap_index];
	arr[swap_index] = arr[pivot_index];
	arr[pivot_index] = temp;
	return (swap_index);
}

void	quicksort_helper(int *arr, int left, int right)
{
	int	pivot_index;

	if (left < right)
	{
		pivot_index = pivot(arr, left, right);
		quicksort_helper(arr, left, pivot_index - 1);
		quicksort_helper(arr, pivot_index + 1, right);
	}
}

int	*create_arr_stack_copy(t_stack_node *stack)
{
	t_stack_node	*current;
	int				size;
	int				i;
	int				*arr;

	current = stack;
	size = find_stack_size(stack);
	i = 0;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

int	*quicksort(t_stack_node *stack)
{
	int	*arr;
	int	size;

	size = find_stack_size(stack);
	arr = create_arr_stack_copy(stack);
	if (arr == NULL)
		return (NULL);
	quicksort_helper(arr, 0, size - 1);
	return (arr);
}
