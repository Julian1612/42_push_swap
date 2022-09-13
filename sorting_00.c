/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:33:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/13 15:34:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	chunk_size;

	chunk_size = get_chunk_size(stack_a);
	while (list_size((*stack_a)) > 0)
	{
		compare_moves_to_b(stack_a, stack_b, chunk_size);
	}
}

int	get_chunk_size(t_node **stack_a)
{
	if (list_size((*stack_a)) < 4)
		return (5);
	else if (list_size((*stack_a)) >= 5)
		return (20);
	else if (list_size((*stack_a)) >= 500)
		return (45);
	else
		return (0);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	while (list_size((*stack_b)) > 0)
		compare_moves_to_a(stack_a, stack_b);
}

void	compare_moves_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_list;

	smallest_list = largest_element_list((*stack_b));
	if (moves_top((*stack_b), smallest_list)
		< moves_buttom(smallest_list))
	{
		while ((*stack_b)->data != smallest_list->data)
			rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->data != smallest_list->data)
			reverse_rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
}

void	compare_moves_to_b(t_node **stack_a, t_node **stack_b, int chunk_size)
{
	t_node	*smallest_top;
	t_node	*smallest_bottom;

	// printf("%d", chunk_size);
	smallest_top = smallest_element_top((*stack_a), chunk_size);
	smallest_bottom = smallest_element_bottom((*stack_a), chunk_size);
	if (moves_top((*stack_a), smallest_top) < moves_buttom(smallest_bottom))
	{
		while ((*stack_a)->data != smallest_top->data)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != smallest_bottom->data)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
}

t_node	*largest_element_list(t_node *head) //namen der variablen in der function anpassen !!!!!!!!!!
{
	int		index;
	int		size_list;
	t_node	*smallest_element;//namen anpassen

	size_list = list_size(head);
	smallest_element = head;
	index = 0;
	while (index < size_list)
	{
		if (smallest_element->data < head->data)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}
