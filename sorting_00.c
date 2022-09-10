/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:33:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/10 18:07:54 by jschneid         ###   ########.fr       */
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
		if (compare_moves(stack_a, &smallest_top, &smallest_bottom) == 1)
		{
			while ((*stack_a)->data != smallest_top->data)
			{
				rotate_a(stack_a);
			}
			push_b(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->data != smallest_bottom->data)
			{
				reverse_rotate_a(stack_a);
			}
			push_b(stack_a, stack_b);
		}
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_list;

	(void) stack_a;
	while (list_size((*stack_b)) > 0)
	{
		smallest_list = smallest_element_list((*stack_b));
		if ()
		{
			/* code */
		}

		// while ((*stack_b)->data != smallest_list->data)
		// {
		// 	reverse_rotate_b(stack_b);
		// }
		// push_a(stack_a, stack_b);
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

int	compare_moves(t_node **head, t_node **top, t_node **buttom)
{
	if (moves_top((*head), (*top)) < moves_buttom((*buttom)))
		return (1);
	else
		return (2);
	return (0);
}

int	moves_top(t_node *head, t_node *top)
{
	int	counter;

	counter = 0;
	while (head != top)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	moves_buttom(t_node *buttom)
{
	int	counter;

	counter = 0;
	while (buttom != NULL)
	{
		counter++;
		buttom = buttom->next;
	}
	return (counter);
}
