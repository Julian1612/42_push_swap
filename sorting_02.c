/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:03:20 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/29 13:42:21 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_node **stack)
{
	if (list_size((*stack)) < 9)
		return (9);
	else if (list_size((*stack)) >= 10)
		return (20);
	else if (list_size((*stack)) >= 500)
		return (50);
	else
		return (0);
}

int	chunk_check(t_node *head, int chunk_start, int chunk_end)
{
	while (head != NULL)
	{
		if (head->data >= chunk_start && head->data <= chunk_end)
			return (1);
		head = head->next;
	}
	return (0);
}

void	sort_three_elemens(t_node **stack_a)
{
	t_node	*second;
	t_node	*third;

	second = get_second_element((*stack_a));
	third = get_third_element((*stack_a));
	if ((*stack_a)->data == 1 && second->data == 0 && third->data == 2)
		swap_a(stack_a);
	else if ((*stack_a)->data == 2 && second->data == 1 && third->data == 0)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->data == 2 && second->data == 0 && third->data == 1)
		rotate_a(stack_a);
	else if ((*stack_a)->data == 0 && second->data == 2 && third->data == 1)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->data == 1 && second->data == 2 && third->data == 0)
		reverse_rotate_a(stack_a);
	printf("ste: %d\n", (*stack_a)->data);
}

t_node	*get_second_element(t_node *stack_a)
{
	int		index;
	t_node	*second_element;

	second_element = NULL;
	index = 0;
	while (index < 1)
	{
		stack_a = stack_a->next;
		index++;
	}
	second_element = stack_a;
	return (second_element);
}

t_node	*get_third_element(t_node *stack_a)
{
	int		index;
	t_node	*third_element;

	third_element = NULL;
	index = 0;
	while (index < 2)
	{
		stack_a = stack_a->next;
		index++;
	}
	third_element = stack_a;
	return (third_element);
}
