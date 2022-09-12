/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:33:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/12 15:28:58 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_top;
	t_node	*smallest_bottom;

	while (list_size((*stack_a)) > 0)
	{
		smallest_top = smallest_element_top((*stack_a));
		smallest_bottom = smallest_element_bottom((*stack_a));
		compare_moves_to_b(stack_a, stack_b, &smallest_top, &smallest_bottom);
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_list;

	while (list_size((*stack_b)) > 0)
	{
		smallest_list = smallest_element_list((*stack_b));
		compare_moves_to_a(stack_a, stack_b, &smallest_list);
	}
}

t_node	*smallest_element_top(t_node *head)
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	smallest_element = head;
	index = 0;
	while (index < (size_list / 2))
	{
		if (smallest_element->data > head->data)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}

t_node	*smallest_element_bottom(t_node *head)
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	index = 0;
	while (index < (size_list / 2))
	{
		head = head->next;
		index++;
	}
	smallest_element = head;
	while (index < size_list)
	{
		if (smallest_element->data > head->data)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}

t_node	*smallest_element_list(t_node *head)
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	smallest_element = head;
	index = 0;
	while (index < size_list)
	{
		if (smallest_element->data > head->data)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}
