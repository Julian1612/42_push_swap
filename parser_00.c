/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/22 23:25:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_list(char** arr) {
	int 	index;
	int 	data;
	t_node	*ret;
	t_node	*head;
	index = 1;

	if (input_check(0, arr, &data))
		return (NULL);
	ret = head = new_node(data);
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
	return ret;
}

static t_node	*arr_to_list(char** arr, int *error)
{
	t_node	*ret;
	t_node	*tmp;
	t_node	*tmp1;
	char	**array;

	if(arr[0] == NULL)
		return NULL;
	array = ft_split(arr[0], ' ');
	ret = tmp1 = create_list(array);
	ft_free(array, array_length(array));
	if (!tmp1)
		*error = 1;
	while (tmp1 && tmp1->next)
		tmp1 = tmp1->next;
	tmp = arr_to_list(&arr[1], error);
	tmp1->next = tmp;
	return(ret);
}

t_node	*parser(int argc, char **argv, t_node *head)
{
	int		error;

	error = 0;
	if (argc == 1) //./pushswap 1
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

int	input_check(int index_1, char **argv, int *value)
{
	size_t		index_2;
	long		current_number;

	// if(duplicate_check(index_1, argv))
	// 	return (1);
	current_number = ft_atoi(argv[index_1]);
	if (current_number > INT_MAX || current_number < INT_MIN)
	{
		write(2, "bError\n", 7);// andern !!!!
		system("leaks push_swap");
		exit(0);
	}
	index_2 = 0;
	while (index_2 < ft_strlen(argv[index_1]))
	{
		if (argv[index_1][index_2] == '-' || argv[index_1][index_2] == '+'
			|| argv[index_1][index_2] == '"' || argv[index_1][index_2] == ' ')
			index_2++;
		if (argv[index_1][index_2] < 48 || argv[index_1][index_2] > 57)
		{
			write(2, "cError\n", 7);
			system("leaks push_swap");
			exit(0);
		}
		index_2++;
	}
	*value = current_number;
	return (0);
}

// int	duplicate_check(int index_1, char **argv)
// {
// 	int	index_2;

// 	index_2 = index_1 + 1;
// 	while (argv[index_2])
// 	{
// 		if (ft_strcmp(argv[index_2], argv[index_1]) == 0)
// 		{
// 			write(2, "dError\n", 7);
// 			return (1);
// 		}
// 		index_2++;
// 	}
// 	return (0);
// }

int	duplicate_check(t_node* head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if(head->data == tmp->data)
			return (1);
			tmp = tmp->next;
		}
		head = head->next;

	}
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
		exit(0);
	free_list(stack_a);
	return (head_indexed);
}
