/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/13 17:34:30 by jschneid         ###   ########.fr       */
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

t_node			*parser(int argc, char **argv, t_node *head);
void			printlist(t_node *head);
t_node			*new_node(int value);
void			swap(t_node **head);
void			rotate(t_node **head);
void			push(t_node **stack_a, t_node **stack_b);
void			reverse_rotate(t_node **head);
t_node			*get_second_node(t_node *head);
int				size_stack(t_node *stack);
t_node			*get_last_node(t_node *head);
int				list_size(t_node *head);
t_node			*get_penultimte_node(t_node *head);
long			ft_atoi(const char *nptr);//anderen namen
int				input_check(int index_1, int argc, char **argv);
void			duplicate_check(int index_1, int argc, char **argv);
void			swap_a(t_node **head);
void			swap_b(t_node **head);
void			swap_stacks(t_node **stack_a, t_node **stack_b);
void			push_a(t_node **stack_a, t_node **stack_b);
void			push_b(t_node **stack_a, t_node **stack_b);
void			rotate_a(t_node **head);
void			rotate_b(t_node **head);
void			reverse_rotate_a(t_node **head);
void			reverse_rotate_b(t_node **head);
void			reverse_rotate_satcks(t_node **stack_a, t_node **stack_b);
void			rotate_stacks(t_node **stack_a, t_node **stack_b);
void			sort_for_index(t_node **stack_a);
void			push_largest_element(t_node **head);
// t_node			get_largest_element(t_node *head);
t_node			*smallest_element_top(t_node *head, int chunk_size);
t_node			*smallest_element_bottom(t_node *head, int chunk_size);
void			compare_moves_to_a(t_node **stack_a, t_node **stack_b);
void			compare_moves_to_b(t_node **stack_a, t_node **stack_b, int chunk_size);
int				moves_top(t_node *head, t_node *top);
int				moves_buttom(t_node *buttom);
void			pre_sort_stack(t_node **stack_a, t_node **stack_b);
void			sort_stack(t_node **stack_a, t_node **stack_b);
t_node			*largest_element_list(t_node *head);
int				get_chunk_size(t_node **stack_a);
void			index_list(t_node *stack_a);
t_node			*smallest_element_list(t_node *head);

#endif
