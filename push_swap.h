/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:11:26 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/17 17:27:52 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

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

long			ft_atol(t_stack_node **a, char **o_av, char **argv, bool flag);

int				count_words(char *str, char separator);
char			*get_next_word(char *str, char separator, int *cursor);
char			**ft_split(char *str, char separator);

t_stack_node	*find_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int nbr);
int				find_stack_size(t_stack_node *head);
void			init_stack(t_stack_node **a, char **argv, bool flag_2_argc);
bool			stack_sorted(t_stack_node *stack);
void			sort(t_stack_node **a, t_stack_node **b);

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

int				*create_arr_stack_copy(t_stack_node *stack);
int				pivot(int *arr, int pivot_index, int end_index);
void			quicksort_helper(int *arr, int left, int right);
int				*quicksort(t_stack_node *stack);
void			mapping_indexes(t_stack_node **stack, int *sorted_arr);

int				determine_chunk_size(int total);
int				has_elements_in_range(t_stack_node **a, int min_i, int max_i);
int				find_closest_from_top(t_stack_node **a, int min_i, int max_i);
int				find_closest_from_btm(t_stack_node **a, int min_i, int max_i);
void			rotate_to_top_stack_a(t_stack_node **a, int min_i, int max_i);
void			get_indexed_stack(t_stack_node **a);
void			greedy_chunked_push(t_stack_node **a, t_stack_node **b);

int				find_max_index_in_stack(t_stack_node **stack);
int				find_max_index_position(t_stack_node **stack, int max_index);
void			rotate_to_top_stack_b(t_stack_node **a, t_stack_node **b);
int				b_has_elements(t_stack_node **b);
void			greedy_max_pull(t_stack_node **a, t_stack_node **b);

int				get_min_value(t_stack_node *a);
int				get_position_of_value(t_stack_node *stack, int value);
void			four_elements_algorithm(t_stack_node **a, t_stack_node **b);
void			five_elements_algorithm(t_stack_node **a, t_stack_node **b);
void			small_stack_algorithm(t_stack_node **a);

#endif