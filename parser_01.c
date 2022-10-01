/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:21:42 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/01 13:49:12 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr_index(t_node *stack_a, t_node *head)
{
	int	index;

	index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->data < head->data)
			index++;
		stack_a = stack_a->next;
	}
	return (index);
}

int	check_if_sorted(t_node *stack_a)
{
	int		index;

	index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->data != index)
			return (1);
		stack_a = stack_a->next;
		index++;
	}
	return (0);
}

int	get_int(int index_1, char **argv, int *value)
{
	long		current_number;

	current_number = ft_atoi(argv[index_1]);
	*value = current_number;
	return (0);
}

// t_node	*index_list(t_node *stack_a)
// {
// 	int		index;
// 	t_node	*indexed_list;
// 	t_node	*tmp;
// 	t_node	*head;
// 	t_node	*head_indexed;

// 	head = stack_a;
// 	indexed_list = new_node(get_nbr_index(stack_a, head));
// 	head_indexed = indexed_list;
// 	head = head->next;
// 	index = (list_size(stack_a) - 1);
// 	while (index > 0)
// 	{
// 		while (indexed_list->next != NULL)
// 			indexed_list = indexed_list->next;
// 		tmp = new_node(get_nbr_index(stack_a, head));
// 		indexed_list->next = tmp;
// 		head = head->next;
// 		index--;
// 	}
// 	free_list(stack_a);
// 	if (check_if_sorted(head_indexed) == 0)
// 	{
// 		free_list(head_indexed);
// 		return (NULL);
// 	}
// 	return (head_indexed);
// }

t_node	*index_list(t_node *stack_a)
{
	t_node	*indexed_list;
	t_node	*tmp;
	t_node	*head;
	t_node	*head_indexed;

	tmp = NULL;
	head = stack_a;
	indexed_list = new_node(get_nbr_index(stack_a, head));
	head_indexed = indexed_list;
	head = head->next;
	indexed_list = i(indexed_list, tmp, head, stack_a);
	free_list(stack_a);
	if (check_if_sorted(head_indexed) == 0)
	{
		free_list(head_indexed);
		return (NULL);
	}
	return (head_indexed);
}

t_node	*i(t_node *indexed_list, t_node *tmp, t_node *head, t_node *stack_a)
{
	int	index;

	index = (list_size(stack_a) - 1);
	while (index > 0)
	{
		while (indexed_list->next != NULL)
			indexed_list = indexed_list->next;
		tmp = new_node(get_nbr_index(stack_a, head));
		indexed_list->next = tmp;
		head = head->next;
		index--;
	}
	return (indexed_list);
}
