/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:21:42 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/29 16:28:23 by jschneid         ###   ########.fr       */
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

int	input_check(int index_1, char **argv, int *value)
{
	size_t		index_2;
	long		current_number;

	current_number = ft_atoi(argv[index_1]);
	if (current_number > INT_MAX || current_number < INT_MIN)
	{
		write(2, "Error\n", 6);
		return(0);

	}
	index_2 = 0;
	while (index_2 < ft_strlen(argv[index_1]))
	{
		if (argv[index_1][index_2] == '-' || argv[index_1][index_2] == '+'
			|| argv[index_1][index_2] == '"' || argv[index_1][index_2] == ' ')
			index_2++;
		if (argv[index_1][index_2] < 48 || argv[index_1][index_2] > 57)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		index_2++;
	}
	*value = current_number;
	return (0);
}

t_node	*index_list(t_node *stack_a)
{
	int		index;
	t_node	*indexed_list;
	t_node	*tmp;
	t_node	*head;
	t_node	*head_indexed;

	head = stack_a;
	indexed_list = new_node(get_nbr_index(stack_a, head));
	head_indexed = indexed_list;
	head = head->next;
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
	if (check_if_sorted(head_indexed) == 0)
	{
		free_list(stack_a);
		free_list(head_indexed);
		exit(0);
	}
	free_list(stack_a);
	return (head_indexed);
}

int	duplicate_check(t_node *head)
{
	t_node	*tmp;

	if (head == NULL)
		return (1);
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
