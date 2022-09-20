/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:33:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/20 14:52:48 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	chunk_size;
	int	chunk;

	chunk = get_chunk_size(stack_a);
	chunk_size = chunk;
	while (list_size((*stack_a)) > 0)
	{
		// printf("stack_b: ");
		// printlist((*stack_b));
		// printf("------------------------------\n");
		// printf("list size: %d\n", list_size((*stack_a)));
		// printf("stack_a: ");
		// printlist((*stack_a));
		// printf("chuk_start           : %d\nchuk_end             : %d\n", (chunk_size - chunk), (chunk_size - 1));
		if (chunk_check((*stack_a), (chunk_size - chunk), (chunk_size - 1)) == 0)
			chunk_size += chunk;
		compare_moves_to_b(stack_a, stack_b, (chunk_size - chunk), (chunk_size - 1));
	}
}

// void	sort_stack(t_node **stack_a, t_node **stack_b)
// {
// 	while (list_size((*stack_b)) > 0)
// 		compare_moves_to_a(stack_a, stack_b);
// }

// void	compare_moves_to_a(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*smallest_list;

// 	smallest_list = largest_element_list((*stack_b));
// 	if (moves_top((*stack_b), smallest_list)
// 		< moves_buttom(smallest_list))
// 	{
// 		while ((*stack_b)->data != smallest_list->data)
// 			rotate_b(stack_b);
// 		push_a(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		while ((*stack_b)->data != smallest_list->data)
// 			reverse_rotate_b(stack_b);
// 		push_a(stack_a, stack_b);
// 	}
// }

void	compare_moves_to_b(t_node **stack_a, t_node **stack_b,
	int chunk_start, int chunks_end)
{
	t_node	*smallest_top;
	t_node	*smallest_bottom;

	smallest_top = smallest_element_top((*stack_a), chunk_start, chunks_end);
	smallest_bottom = smallest_element_bottom((*stack_a),
			chunk_start, chunks_end);
	// printf("smallest_top    (ra) : %d\n", smallest_top->data);
	// printf("smallest_bottom (rra): %d\n", smallest_bottom->data);
	// printf("move_top        (ra) : %d\nmoves_bottom    (rra): %d\n", moves_top((*stack_a), smallest_top, chunk_start, chunks_end), moves_buttom(smallest_bottom, chunk_start, chunks_end));
	if (moves_top((*stack_a), smallest_top, chunk_start, chunks_end) < 0)
	{
		while ((*stack_a)->data != smallest_bottom->data)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		return ;
	}
	if (moves_buttom(smallest_bottom, chunk_start, chunks_end) < 0)
	{
		while ((*stack_a)->data != smallest_top->data)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		return ;
	}
	if (moves_top((*stack_a), smallest_top, chunk_start, chunks_end)
		> moves_buttom(smallest_bottom, chunk_start, chunks_end))
	{
		while ((*stack_a)->data != smallest_bottom->data)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != smallest_top->data)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
}

int	get_chunk_size(t_node **stack)
{
	if (list_size((*stack)) < 9)
		return (0);
	else if (list_size((*stack)) >= 10)
		return (20);
	else if (list_size((*stack)) >= 500)
		return (50);
	else
		return (0);
}
