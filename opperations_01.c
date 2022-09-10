/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:22:27 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/09 13:01:06 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **head_one, t_node **head_two)
{
	t_node	*temp;

	if (head_one == NULL || head_two == NULL)
		return ;
	temp = (*head_two);
	(*head_two) = (*head_one);
	(*head_one) = (*head_one)->next;
	(*head_two)->next = temp;
}

// (sa) Swap the first 2 elements at the top of stack a
void	swap_a(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		swap(head);
		ft_printf("sa\n");
	}
}

// (sb) Swap the first 2 elements at the top of stack b
void	swap_b(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		swap(head);
		ft_printf("sb\n");
	}
}

// (ss) Take the first element at the top of b and put it at the top of a
void	swap_stacks(t_node **stack_a, t_node **stack_b)
{
	if (list_size((*stack_a)) > 1 && list_size((*stack_b)) > 1)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}

// (pa) Take the first element at the top of b and put it at the top of a.
void	push_a(t_node **stack_a, t_node **stack_b)
{
	if (list_size((*stack_b)) > 0)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
