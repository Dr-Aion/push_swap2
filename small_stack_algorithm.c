/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:00:50 by amoldagu          #+#    #+#             */
/*   Updated: 2025/07/15 19:50:30 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int get_min_value(t_stack_node *a)
{
    t_stack_node *current;
    int min;
    if(a == NULL)
        return (0);

    current = a;
    min = current->value;
    current = current->next;
    while(current)
    {
        if(min > current->value)
            min = current->value;
        current = current->next;
    }
    printf("%d\n", min);
    return (min);
}

void small_stack_algorithm(t_stack_node **a)
{
    int first;
    int second;
    int third;

    if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
        return;

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

void four_elements_algorithm(t_stack_node **a, t_stack_node **b)
{
    int min;

    min = get_min_value(*a);
    while((*a)->value != min)
        ra(a);
    pb(a, b);
    small_stack_algorithm(a);
    pa(b, a);
}

void five_elements_algorithm(t_stack_node **a, t_stack_node **b)
{
    int min;
    int second_min;
    min = get_min_value(*a);
    while((*a)->value != min)
        ra(a);
    if((*a) && (*a)->next)
        pb(a, b);
    second_min = get_min_value(*a);
    while((*a)->value != second_min)
        ra(a);
    pb(a, b);
    small_stack_algorithm(a);
    if(*b)
        pa(b, a);
    if(*b)
        pa(b, a);
}