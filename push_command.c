/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:01:13 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/14 13:43:16 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*src_head;

	if (!src || !(*src) || !dst)
		return ;
	src_head = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)-> prev = NULL;
	if (!(*dst))
	{
		(*dst) = src_head;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
		return ;
	}
	src_head->next = (*dst);
	(*dst)->prev = src_head;
	src_head->prev = NULL;
	(*dst) = src_head;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
