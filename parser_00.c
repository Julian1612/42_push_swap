/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/15 18:21:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parser(int argc, char **argv, t_node *head)
{
	int		index;
	t_node	*tmp;

	if (argc == 2)
	{
		write(2, "aError\n", 7);
		exit(0);
	}
	index = argc - 1;
	while (index > 0)
	{
		tmp = new_node(input_check(index, argc, argv));
		tmp->next = head;
		head = tmp;
		index--;
	}
	return (head);
}

t_node	*new_node(int value)
{
	t_node	*stack;

	stack = (t_node *) malloc(sizeof(t_node));
	stack->data = value;
	stack->next = NULL;
	return (stack);
}

int	input_check(int index_1, int argc, char **argv)
{
	size_t		index_2;
	long		current_number;

	duplicate_check(index_1, argc, argv);
	current_number = ft_atoi(argv[index_1]);
	if (current_number > INT_MAX || current_number < INT_MIN)
	{
		write(2, "bError\n", 7);
		exit(0);
	}
	index_2 = 0;
	while (index_2 < ft_strlen(argv[index_1]))
	{
		if (argv[index_1][index_2] == '-' || argv[index_1][index_2] == '+')
			index_2++;
		if (argv[index_1][index_2] < 48 || argv[index_1][index_2] > 57)
		{
			write(2, "cError\n", 7);
			exit(0);
		}
		index_2++;
	}
	return (current_number);
}

void	duplicate_check(int index_1, int argc, char **argv) /// nochmal checken ob wirklich funktioniert
{
	int	index_2;

	index_2 = argc - 1;
	while (index_2 > 0)
	{
		if (index_2 == index_1)
			index_2--;
		if (index_2 == 0)
			return ;
		if (ft_atoi(argv[index_1]) == ft_atoi(argv[index_2]))
		{
			write(2, "dError\n", 7);
			exit(0);
		}
		index_2--;
	}
}

// muss am schluss die andee linked list noch geloscht werden ????
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
	return (head_indexed);
}
