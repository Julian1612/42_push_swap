/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/29 18:29:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
////////////////////
# include <stdio.h>
////////////////////

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

struct s_node	*parser(int argc, char **argv, t_node *head);
void			printlist(t_node *head);
struct s_node	*new_node(int value);
void			sawp_stack_a(t_node *head);
t_node			*get_node_2(t_node *head);

#endif
