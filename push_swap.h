/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:11:26 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/15 19:50:35 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_check_for_repetition(t_stack_node *a, int nbr);
int				is_valid_number(char *str);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack);
void			free_my_argv(char **my_argv);

int				count_words(char *str, char separator);
char			*get_next_word(char *str, char separator, int *cursor);
char			**ft_split(char *str, char separator);

long			ft_atol(t_stack_node **a, char **argv, bool flag_argc_2);
t_stack_node	*find_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int nbr);
void			init_stack(t_stack_node **a, char **argv, bool flag_2_argc);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
int				find_stack_size(t_stack_node *head);

int				*create_arr_stack_copy(t_stack_node *stack);
int				pivot(int *arr, int pivot_index, int end_index);
void			quicksort_helper(int *arr, int left, int right);
int				*quicksort(t_stack_node *stack);
void			mapping_indexes(t_stack_node **stack, int *sorted_arr);

int				determine_chunk_size(int total);
int				has_elements_in_range(t_stack_node **stack, int min_index, int max_index);
int				find_closest_from_top(t_stack_node **stack, int min_index, int max_index);
int				find_closest_from_bottom(t_stack_node **stack, int min_index, int max_index);
void			rotate_to_top_stack_a(t_stack_node **a, int min_index, int max_index);
void			get_indexed_stack(t_stack_node **a);
void			greedy_chunked_push(t_stack_node **a, t_stack_node **b);
int				find_max_index_in_stack(t_stack_node **stack);
int				find_max_index_position(t_stack_node **stack, int max_index);
void			rotate_to_top_stack_b(t_stack_node **a, t_stack_node **b);
int				b_has_elements(t_stack_node **b);
int				get_min_value(t_stack_node *a);
void			four_elements_algorithm(t_stack_node **a, t_stack_node **b);
void			five_elements_algorithm(t_stack_node **a, t_stack_node **b);
				
void			small_stack_algorithm(t_stack_node **a);
bool			stack_sorted(t_stack_node *stack);
void			greedy_max_pull(t_stack_node **a, t_stack_node **b);

void			print_nodes(t_stack_node *head);
void			print_indexes(t_stack_node *head);

#endif