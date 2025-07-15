#include "push_swap.h"

void	print_nodes(t_stack_node *head)
{
	t_stack_node *current;

	current = head;
	if (head == NULL)
		return ;
	while (current)
	{
		printf("%d", current->value);
		if (current->next)
			printf("->");
		if (!current->next)
			printf("\n");
		current = current->next;
	}
}

void	print_indexes(t_stack_node *head)
{
	t_stack_node *current;

	current = head;
	if (head == NULL)
		return ;
	while (current)
	{
		printf("%d", current->index);
		if (current->next)
			printf("->");
		if (!current->next)
			printf("\n");
		current = current->next;
	}
}