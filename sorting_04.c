/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/22 15:24:59 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_smallest_node(t_node *stack_a)
{
	t_node	*smallest_element;

	smallest_element = NULL;
	while (stack_a->data != 0)
		stack_a = stack_a->next;
	smallest_element = stack_a;
	return (smallest_element);
}

t_node	*get_biggest_node(t_node *stack_a)
{
	t_node	*biggest_element;

	biggest_element = NULL;
	biggest_element = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->data > biggest_element->data)
		{
			biggest_element = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (biggest_element);
}

void	swap_smallest_on_top(t_node **stack_b)
{
	t_node	*smallest_element;

	if (list_size((*stack_b)) > 1)
	{
		smallest_element = smallest_element_list((*stack_b));
		while ((*stack_b)->data == smallest_element->data)
			rotate_b(stack_b);
	}
}
