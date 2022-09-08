/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:26:57 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/08 10:43:11 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (pb) Take the first element at the top of a and put it at the top of b.
void	push_b(t_node **stack_a, t_node **stack_b)
{
	if (list_size((*stack_a)) > 0)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

// (ra) Shift up all elements of stack a by 1
void	rotate_a(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		rotate(head);
		ft_printf("ra\n");
	}
}

// (rb) Shift up all elements of stack b by 1
void	rotate_b(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		rotate(head);
		ft_printf("rb\n");
	}
}

// (rr) ra and rb at the same time
void	rotate_stacks(t_node **stack_a, t_node **stack_b)
{
	if (list_size((*stack_a)) > 1 && list_size((*stack_b)) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}
