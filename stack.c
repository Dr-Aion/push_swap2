/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:40:50 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/17 17:24:29 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stack_size(t_stack_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack_node **a, char **argv, bool flag_2_argc)
{
	long	num;
	int		i;
	char	**orgininal_argv;

	i = 0;
	orgininal_argv = argv;
	while (*argv)
	{
		if (!is_valid_number(argv[i]))
			error_free(a, orgininal_argv, flag_2_argc);
		num = ft_atol(a, orgininal_argv, argv, flag_2_argc);
		if (error_check_for_repetition(*a, (int)num))
			error_free(a, orgininal_argv, flag_2_argc);
		append_node(a, (int)num);
		argv++;
	}
	if (flag_2_argc)
		free_my_argv(orgininal_argv);
}
