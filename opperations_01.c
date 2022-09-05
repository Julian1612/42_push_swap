/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:22:27 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/05 17:30:10 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both_stacks(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}

void	push_to_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (get_list_size((*stack_a)) == 0)
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = temp;
}
