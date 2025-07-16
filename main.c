/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:14:02 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/16 18:12:26 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	stack_size;

	if (!stack_sorted(*a))
	{
		stack_size = find_stack_size(*a);
		if (stack_size == 2)
			sa(a);
		else if (stack_size == 3)
			small_stack_algorithm(a);
		else if (stack_size == 4)
			four_elements_algorithm(a, b);
		else if (stack_size == 5)
			five_elements_algorithm(a, b);
		else
			greedy_max_pull(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**my_argv;

	a = NULL;
	b = NULL;
	if ((argc == 1) || ((argc == 2) && !(argv[1][0])))
		return (1);
	else if (argc == 2)
	{
		my_argv = ft_split(argv[1], ' ');
		if (my_argv == NULL)
			return (1);
		init_stack(&a, my_argv, argc == 2);
	}
	else
	{
		init_stack(&a, argv + 1, argc == 2);
	}
	sort(&a, &b);
	free_stack(&a);
}
