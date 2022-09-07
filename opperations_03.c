/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:27:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/07 14:55:34 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}

void	reverse_rotate_satcks(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
