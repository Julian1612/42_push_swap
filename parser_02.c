/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:25:46 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/01 13:48:57 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*stack;

	stack = (t_node *) malloc(sizeof(t_node));
	stack->data = value;
	stack->next = NULL;
	return (stack);
}

int	array_length(char **a)
{
	int	index;

	index = 0;
	while (a[index] != NULL)
		index++;
	return (index);
}

int	duplicate_check(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}
