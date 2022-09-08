/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:33:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/08 15:43:07 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_index(t_node **stack_a)
{
	int		index;
	t_node	*comparable;
	t_node	*head;
	t_node	*list;

	head = (*stack_a);
	list = (*stack_a);
	index = 0;
	while ((*stack_a) != NULL)
	{
		comparable = (*stack_a);
		while (head != NULL)
		{
			if (head->data < comparable->data)
				comparable = head;
			head = head->next;
		}
		(*stack_a)->data = index;
		(*stack_a) = (*stack_a)->next;
		head = list;
		index++;
	}
}
