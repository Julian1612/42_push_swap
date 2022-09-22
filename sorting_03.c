/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:31 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/22 15:13:25 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_elements(t_node **stack_a, t_node **stack_b) // nae andern moe tahn foe oder so ka
{
	t_node	*smallest_element;
	t_node	*biggest_element;

	smallest_element = get_smallest_node((*stack_a));
	biggest_element = get_biggest_node((*stack_a));
	push_biggest_element(stack_a, stack_b, biggest_element);
	push_smallest_element(stack_a, stack_b, smallest_element);
	sort_elements(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	sort_elements(t_node **stack_a)
{
	t_node	*second;
	t_node	*third;

	second = get_second_element((*stack_a));
	if (list_size((*stack_a)) == 2 && (*stack_a)->data == 2
		&& second->data == 1)
	{
		swap_a(stack_a);
		return ;
	}
	third = get_third_element((*stack_a));
	sort_element_util((*stack_a), second, third);
}

void	sort_element_util(t_node *stack_a, t_node *second, t_node *third)
{
	if (stack_a->data == 2 && second->data == 1 && third->data == 3)
		swap_a(&stack_a);
	else if (stack_a->data == 3 && second->data == 2 && third->data == 1)
	{
		swap_a(&stack_a);
		reverse_rotate_a(&stack_a);
	}
	else if (stack_a->data == 3 && second->data == 1 && third->data == 2)
		rotate_a(&stack_a);
	else if (stack_a->data == 1 && second->data == 3 && third->data == 2)
	{
		swap_a(&stack_a);
		rotate_a(&stack_a);
	}
	else if (stack_a->data == 2 && second->data == 3 && third->data == 1)
		reverse_rotate_a(&stack_a);
}

void	push_smallest_element(t_node **stack_a, t_node **stack_b,
	t_node *smallest_element)
{
	if (moves_top((*stack_a), smallest_element)
		> moves_buttom(smallest_element))
	{
		while ((*stack_a)->data != smallest_element->data)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != smallest_element->data)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
}

void	push_biggest_element(t_node **stack_a, t_node **stack_b,
	t_node *biggest_element)
{
	if (moves_top((*stack_a), biggest_element) > moves_buttom(biggest_element))
	{
		while ((*stack_a)->data != biggest_element->data)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != biggest_element->data)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
}
