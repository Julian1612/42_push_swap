/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:27:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/08 10:43:55 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (rra) Shift down all elements of stack a by 1
void	reverse_rotate_a(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		reverse_rotate(head);
		ft_printf("rra\n");
	}
}

// (rrb) Shift down all elements of stack b by 1
void	reverse_rotate_b(t_node **head)
{
	if (list_size((*head)) > 1)
	{
		reverse_rotate(head);
		ft_printf("rrb\n");
	}
}

// (rrr) rra and rrb at the same time
void	reverse_rotate_satcks(t_node **stack_a, t_node **stack_b)
{
	if (list_size((*stack_a)) > 1 && list_size((*stack_b)) > 1)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
}
