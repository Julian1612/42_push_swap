/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/01 19:53:13 by jschneid         ###   ########.fr       */
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
	if (get_int(0, arr, &data))
		return (NULL);
	ret = new_node(data);
	head = ret;
	while (arr[index])
	{
		if (get_int(index, arr, &data))
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
	int		tmp;

	error = 0;
	tmp = 0;
	if (argc < 2)
		exit(0);
	if (ft_strlen(argv[1]) == 0)
		return (NULL);
	// while(argv[1][tmp] == 32 && argv[1])
	// 	tmp++;
	// if (!argv[1][tmp])
	// 	return (NULL);
	input_checker(argv);
	head = arr_to_list(&argv[1], &error);
	error += duplicate_check(head);
	if (list_size(head) == 1)
	{
		free_list(head);
		exit(0);
	}
	if (error)
	{
		free_list(head);
		return (NULL);
	}
	return (head);
}

int	input_checker(char **argv)
{
	long		current_number;
	int			index_1;

	index_1 = 1;
	while (argv[index_1])
	{
		current_number = ft_atoi(argv[index_1]);
		if (current_number > INT_MAX || current_number < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (character_checker(argv, index_1))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		index_1++;
	}
	return (0);
}

int	character_checker(char **argv, int index_1)
{
	size_t	index_2;
	char	**string;

	index_2 = 0;
	string = ft_split(&argv[index_1][index_2], ' ');
	if (string[0] == NULL)
		return (1);
	if (check_charakters(string) == 1)
	{
		ft_free(string, array_length(string));
		return (1);
	}
	ft_free(string, array_length(string));
	return (0);
}
