/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:47:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/23 11:10:19 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node *head)
{
	int		index;
	int		size_list;
	t_node	*last_node;
	t_node	*stack_a;

	if (head == NULL)
		return (NULL);
	stack_a = head;
	size_list = list_size(head);
	index = 1;
	while (stack_a != NULL)
	{
		if (index == size_list)
			last_node = stack_a;
		stack_a = stack_a->next;
		index++;
	}
	return (last_node);
}

int	list_size(t_node *head)
{
	int	index;

	if (head == NULL)
		return (0);
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

	if (head == NULL)
		return (NULL);
	stack_a = head;
	index = 0;
	while (stack_a != NULL && index < 1)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (stack_a);
}

t_node	*get_penultimte_node(t_node *head)
{
	int		index;
	t_node	*stack_a;

	if (head == NULL)
		return (NULL);
	stack_a = head;
	index = 1;
	while (stack_a != NULL && index < (list_size(head) - 1))
	{
		stack_a = stack_a->next;
		index++;
	}
	return (stack_a);
}

void	free_list(t_node *list)
{
	t_node	*tmp;

	tmp = NULL;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
