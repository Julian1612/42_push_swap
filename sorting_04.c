/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/29 14:40:34 by jschneid         ###   ########.fr       */
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

void	sorting(t_node **stack_a, t_node **stack_b, int chunk, int chunk_size)
{
	if (list_size(*stack_a) == 2)
		swap_a(stack_a);
	else if (list_size(*stack_a) == 3)
		sort_three_elemens(stack_a);
	else if (list_size(*stack_a) == 4 || list_size(*stack_a) == 5)
		sort_five_elements(stack_a, stack_b);
	else
	{
		pre_sort_stack(stack_a, stack_b, chunk, chunk_size);
		sort_stack(stack_a, stack_b);
	}
	printf("sorting: %d\n", (*stack_a)->data);
}
