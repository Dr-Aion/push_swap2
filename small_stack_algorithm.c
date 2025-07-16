/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:00:50 by amoldagu          #+#    #+#             */
/*   Updated: 2025/07/16 18:23:58 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_stack_algorithm(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	four_elements_algorithm(t_stack_node **a, t_stack_node **b)
{
	int	min;
	int	pos;

	min = get_min_value(*a);
	pos = get_position_of_value(*a, min);
	if (pos <= 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(b, a);
	small_stack_algorithm(a);
	pa(a, b);
}

void	five_elements_algorithm(t_stack_node **a, t_stack_node **b)
{
	int	min;
	int	pos;

	min = get_min_value(*a);
	pos = get_position_of_value(*a, min);
	if (pos <= 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(b, a);
	four_elements_algorithm(a, b);
	pa(a, b);
}
