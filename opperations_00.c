/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:32:57 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/29 18:54:15 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sawp_stack_a(t_node *head)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = head;
	node_2 = get_node_2(head);
	printf("NODE_1: %d\nNODE_2: %d\n", node_1->value, node_2->value);
}

t_node	*get_node_2(t_node *head)
{
	int		index;
	t_node	*stack_a;

	stack_a = head;
	index = 0;
	while (stack_a != NULL && index < 1)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (stack_a);
}
