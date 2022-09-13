/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/13 17:34:27 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parser(int argc, char **argv, t_node *head)
{
	int		index;
	t_node	*tmp;

	if (argc == 2)
	{
		write(2, "Error\n", 6);
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

	stack = NULL;
	stack = malloc(sizeof(stack));
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
		write(2, "Error\n", 6);
		exit(0);
	}
	index_2 = 0;
	while (index_2 < ft_strlen(argv[index_1]))
	{
		if (argv[index_1][index_2] == '-' || argv[index_1][index_2] == '+')
			index_2++;
		if (argv[index_1][index_2] < 48 || argv[index_1][index_2] > 57)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		index_2++;
	}
	return (current_number);
}

void	duplicate_check(int index_1, int argc, char **argv)
{
	int	index_2;

	index_2 = argc - 1;
	while (index_2 > 0)
	{
		if (index_2 == index_1)
			index_2--;
		if (ft_atoi(argv[index_1]) == ft_atoi(argv[index_2]))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		index_2--;
	}
}

void	index_list(t_node *stack_a)
{
	int		index;
	t_node	*smallest_element;
	t_node	*head;

	smallest_element = smallest_element_list(stack_a);
	head = stack_a;
	index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->data < smallest_element->data)
		{
			stack_a->data = index;
		}
		index++;
		stack_a = stack_a->next;
	}
}

t_node	*smallest_element_list(t_node *head)
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	smallest_element = head;
	index = 0;
	while (index < size_list)
	{
		if (smallest_element->data < head->data)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}

void	printlist(t_node *head)
{
	t_node	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		printf("%d - ", temporary->data);
		temporary = temporary->next;
	}
	printf("\n");
}
