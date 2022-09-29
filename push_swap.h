/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/29 13:40:36 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"
////////////////////
# include <stdio.h>
////////////////////

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

t_node	*parser(int argc, char **argv, t_node *head);
void	printlist(t_node *head);
t_node	*new_node(int value);
void	swap(t_node **head);
void	rotate(t_node **head);
void	push(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **head);
t_node	*get_second_node(t_node *head);
int		size_stack(t_node *stack);
t_node	*get_last_node(t_node *head);
int		list_size(t_node *head);
t_node	*get_penultimte_node(t_node *head);
int		input_check(int index_1, char **argv, int *value);
int		duplicate_check(t_node *head);
void	swap_a(t_node **head);
void	swap_b(t_node **head);
void	swap_stacks(t_node **stack_a, t_node **stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	reverse_rotate_a(t_node **head);
void	reverse_rotate_b(t_node **head);
void	reverse_rotate_satcks(t_node **stack_a, t_node **stack_b);
void	rotate_stacks(t_node **stack_a, t_node **stack_b);
void	sort_for_index(t_node **stack_a);
void	push_largest_element(t_node **head);
t_node	*smallest_element_top(t_node *head, int chunk_start, int chunk_end);
t_node	*smallest_element_bottom(t_node *head, int chunk_start, int chunk_end);
void	compare_moves_to_a(t_node **stack_a, t_node **stack_b);
void	compare_moves_to_b(t_node **stack_a, t_node **stack_b,
			int chunk_start, int chunks_end);
int		moves_top(t_node *head, t_node *top);
int		moves_buttom(t_node *buttom);
void	pre_sort_stack(t_node **stack_a, t_node **stack_b,
			int chunk, int chunk_size);
void	sort_stack(t_node **stack_a, t_node **stack_b);
t_node	*smallest_element_list(t_node *head);
int		get_chunk_size(t_node **stack_a);
t_node	*index_list(t_node *stack_a);
t_node	*smallest_element_list(t_node *head);
int		get_nbr_index(t_node *stack_a, t_node *head);
int		chunk_check(t_node *head, int chunk_start, int chunk_end);
void	swap_smallest_on_top(t_node **stack_b);
t_node	*get_first_element(t_node *stack_a);
t_node	*get_second_element(t_node *stack_a);
t_node	*get_third_element(t_node *stack_a);
t_node	*get_fifth_element(t_node *stack_a);
void	sort_three_elemens(t_node **stack_a);
void	sort_five_elemens(t_node **stack_a, t_node **stack_b);
void	push_first_and_last(t_node **stack_a, t_node **stack_b,
			t_node **first, t_node **fifth);
void	free_list(t_node *list);
int		check_if_sorted(t_node *stack_a);
t_node	*get_smallest_node(t_node *stack_a);
void	push_smallest_element(t_node **stack_a, t_node **stack_b,
			t_node *smallest_element);
void	sort_five_elements(t_node **stack_a, t_node **stack_b);
t_node	*get_biggest_node(t_node *stack_a);
void	push_last_element(t_node **stack_a, t_node **stack_b);
void	push_biggest_element(t_node **stack_a, t_node **stack_b,
			t_node *biggest_element);
void	sort_elements(t_node **stack_a);
void	sort_element_util(t_node *stack_a, t_node *second, t_node *third);
void	move_to_b(t_node **stack_a, t_node **stack_b,
			t_node *smallest_top, t_node *smallest_bottom);
int		array_length(char **a);
void	sorting(t_node **stack_a, t_node **stack_b, int chunk, int chunk_size);

#endif
