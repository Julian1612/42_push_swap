/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:22:48 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/22 23:23:02 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*index_list(t_node *stack_a)
{
	int		index;
	t_node	*indexed_list;
	t_node	*tmp;
	t_node	*head;
	t_node	*head_indexed;

	head = stack_a;
	indexed_list = new_node(get_nbr_index(stack_a, head));
	head_indexed = indexed_list;
	head = head->next;
	index = (list_size(stack_a) - 1);
	while (index > 0)
	{
		while (indexed_list->next != NULL)
			indexed_list = indexed_list->next;
		tmp = new_node(get_nbr_index(stack_a, head));
		indexed_list->next = tmp;
		head = head->next;
		index--;
	}
	if (check_if_sorted(head_indexed) == 0)
		exit(0);
	free_list(stack_a);
	return (head_indexed);
}
