/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:47:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/01 11:49:11 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node *head)
{
	int		index;
	int		list_size;
	t_node	*last_node;
	t_node	*stack_a;

	stack_a = head;
	list_size = get_list_size(head);
	index = 1;
	while (stack_a != NULL)
	{
		if (index == list_size)
			last_node = stack_a;
		stack_a = stack_a->next;
		index++;
	}
	return (last_node);
}

int	get_list_size(t_node *head)
{
	int	index;

	index = 0;
	while (head != NULL)
	{
		head = head->next;
		index++;
	}
	return (index);
}

t_node	*get_second_node(t_node *head)
{
	int		index;
	t_node	*stack_a;

	stack_a = head;
	index = 0;
	while (stack_a != NULL && index < 1)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (stack_a);
}
