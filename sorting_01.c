/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:38 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/12 16:56:25 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_moves_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_list;

	smallest_list = smallest_element_list((*stack_b));
	if (moves_top((*stack_b), smallest_list)
		< moves_buttom(smallest_list))
	{
		while ((*stack_b)->data != smallest_list->data)
		{
			rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->data != smallest_list->data)
		{
			reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void	compare_moves_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_top;
	t_node	*smallest_bottom;

	smallest_top = smallest_element_top((*stack_a));
	smallest_bottom = smallest_element_bottom((*stack_a));
	if (moves_top((*stack_a), smallest_top) < moves_buttom(smallest_bottom))
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
