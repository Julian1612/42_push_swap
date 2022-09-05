/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:32:57 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/05 17:30:32 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **head)
{
	t_node	*node_2;
	t_node	*temporary;

	node_2 = get_second_node(*head);
	temporary = node_2->next;
	(*head)->next = temporary;
	node_2->next = *head;
	*head = node_2;
}

void	swap_both_stacks(t_node **stack_a, t_node **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}

void	rotate_stack(t_node **head)
{
	t_node	*last_node;
	t_node	*node_2;
	t_node	*temporary;

	last_node = get_last_node(*head);
	node_2 = get_second_node(*head);
	temporary = (*head);
	(*head) = node_2;
	last_node->next = temporary;
	temporary->next = NULL;
}

void	rotate_both_stacks(t_node **stack_a, t_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	reverse_rotate_stack(t_node **head)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*temporary;

	last_node = get_last_node(*head);
	penultimate_node = get_penultimte_node(*head);
	temporary = (*head);
	(*head) = last_node;
	last_node->next = temporary;
	penultimate_node->next = NULL;
}
