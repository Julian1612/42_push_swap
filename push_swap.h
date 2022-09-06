/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/06 10:20:50 by jschneid         ###   ########.fr       */
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
void			swap_stack(t_node **head);
void			rotate_stack(t_node **head);
void			push_to_stack(t_node **stack_a, t_node **stack_b);
void			reverse_rotate_stack(t_node **head);
t_node			*get_second_node(t_node *head);
int				size_stack(t_node *stack);
t_node			*get_last_node(t_node *head);
int				get_list_size(t_node *head);
t_node			*get_penultimte_node(t_node *head);
void			reverse_rotate_both_stacks(t_node **stack_a, t_node **stack_b);
void			rotate_both_stacks(t_node **stack_a, t_node **stack_b);
void			swap_both_stacks(t_node **stack_a, t_node **stack_b);
long			ft_atoi(const char *nptr);//anderen namen
int				input_check(int index_1, int argc, char **argv);
void			duplicate_checker(int index_1, int argc, char **argv);

#endif
