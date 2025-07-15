/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_max_pull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:53:28 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/15 19:36:21 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max_index_in_stack(t_stack_node **stack)
{
    t_stack_node *current;
    int max;
    
    if (stack == NULL || (*stack) == NULL)
        return (-1);
    current = *stack;
    max = current->index;
    current = current->next;
    while(current)
    {
        if(max < current->index)
            max = current->index;
        current = current->next;
    }
    return (max);
}

int find_max_index_position(t_stack_node **stack, int max_index)
{
    t_stack_node *current;
    int i;

    if(stack == NULL || (*stack) == NULL)
        return (-1);
    current = (*stack);
    i = 0;
    while (current)
    {
        if(current->index == max_index)
            return (i);
        i++;
        current = current->next;
    }
    return (-1);
}

void rotate_to_top_stack_b(t_stack_node **a, t_stack_node **b)
{
    int total;
    int pos;
    int max_index;

    if (b == NULL || (*b) == NULL)
        return ;
    total = find_stack_size(*b);
    max_index = find_max_index_in_stack(b);
    pos = find_max_index_position(b, max_index);
    if(pos < total / 2)
    {
        while (*b && ((*b)-> index != max_index))
            rb(b);
    }
    else
    {
        while (*b && ((*b)->index != max_index))
            rrb(b);
    }
	pa(a, b);
}

int b_has_elements(t_stack_node **b)
{
    return (b && (*b));
}

void greedy_max_pull(t_stack_node **a, t_stack_node **b)
{
    if(a == NULL || (*a) == NULL)
        return ;
    greedy_chunked_push(a, b);
    while (b_has_elements(b))
        rotate_to_top_stack_b(a, b);
}