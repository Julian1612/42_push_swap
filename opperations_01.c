/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:22:27 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/07 15:54:50 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (get_list_size((*stack_a)) == 0)
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = temp;
}

void	swap_a(t_node **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	swap_b(t_node **head)
{
	swap(head);
	ft_printf("sb\n");
}

void	swap_stacks(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
