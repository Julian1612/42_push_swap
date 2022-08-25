/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/25 17:34:48 by jschneid         ###   ########.fr       */
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

int				main(int argc, char **argv);
struct s_node	*new_node(int value);
void			printlist(t_node *head);
void	parser(int argc, char **argv);

#endif
