/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_chunked_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:27:28 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/16 18:11:01 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_chunked_push(t_stack_node **a, t_stack_node **b)
{
	int	total;
	int	min_index;
	int	max_index;
	int	cur_index;

	get_indexed_stack(a);
	total = find_stack_size(*a);
	min_index = 0;
	while (min_index < total)
	{
		max_index = min_index + determine_chunk_size(total) - 1;
		if (max_index >= total)
			max_index = total - 1;
		if (a == NULL || (*a) == NULL)
			break ;
		while (has_elements_in_range(a, min_index, max_index))
		{
			rotate_to_top_stack_a(a, min_index, max_index);
			cur_index = (*a)->index;
			pb(b, a);
			if (cur_index > (total / 2))
				rb(b);
		}
		min_index += determine_chunk_size(total);
	}
}
