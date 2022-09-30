/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/30 13:57:04 by jschneid         ###   ########.fr       */
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

	error = 0;
	if (argc < 2)
		exit(0);
	if (ft_strlen(argv[1]) == 0)
		return (NULL);
	input_checker(argv);
	head = arr_to_list(&argv[1], &error);
	error += duplicate_check(head);
	if (list_size(head) == 1)
	{
		free_list(head);
		exit(1);
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
	while (argv[index_1] != '\0')
	{
		current_number = ft_atoi(argv[index_1]);
		if (current_number > INT_MAX || current_number < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		character_checker(argv, index_1);
		index_1++;
	}
	return (0);
}

void	character_checker(char **argv, int index_1)
{
	size_t	index_2;

	index_2 = 0;
	while (index_2 < ft_strlen(argv[index_1]))
	{
		if (argv[index_1][index_2] == '-' || argv[index_1][index_2] == '+'
			|| argv[index_1][index_2] == '"' || argv[index_1][index_2] == ' ')
		index_2++;
		if (argv[index_1][index_2] < 48 || argv[index_1][index_2] > 57)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		index_2++;
	}
}
