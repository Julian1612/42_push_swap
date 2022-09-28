/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/28 15:33:51 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_list(char **arr)
{
	int		index;
	int		data;
	t_node	*ret;
	t_node	*head;

	index = 1;
	if (input_check(0, arr, &data))
		return (NULL);
	ret = new_node(data);
	head = ret;
	while (arr[index])
	{
		if (input_check(index, arr, &data))
		{
			free_list(ret);
			return (NULL);
		}
		head->next = new_node(data);
		head = head->next;
		head->next = NULL;
		index++;
	}
	return (ret);
}

static t_node	*arr_to_list(char **arr, int *error)
{
	t_node	*ret;
	t_node	*tmp;
	t_node	*tmp1;
	char	**array;

	if (arr[0] == NULL)
		return (NULL);
	array = ft_split(arr[0], ' ');
	tmp1 = create_list(array);
	ret = tmp1;
	ft_free(array, array_length(array));
	if (!tmp1)
		*error = 1;
	while (tmp1 && tmp1->next)
		tmp1 = tmp1->next;
	tmp = arr_to_list(&arr[1], error);
	tmp1->next = tmp;
	return (ret);
}

t_node	*parser(int argc, char **argv, t_node *head)
{
	int		error;

	error = 0;
	if (argc == 1)
		exit(0);
	head = arr_to_list(&argv[1], &error);
	error += duplicate_check(head);
	if (error)
	{
		free_list(head);
		return (NULL);
	}
	return (head);
}

int	array_length(char **a)
{
	int	index;

	index = 0;
	while (a[index] != NULL)
		index++;
	return (index);
}

t_node	*new_node(int value)
{
	t_node	*stack;

	stack = (t_node *) malloc(sizeof(t_node));
	stack->data = value;
	stack->next = NULL;
	return (stack);
}
