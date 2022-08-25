/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/25 17:34:00 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser(int argc, char **argv)
{
	int		index;
	t_node	*head;
	t_node	*tmp;

	(void) argc;
	head = NULL;
	index = 1;
	while (index < argc)
	{
		tmp = new_node(ft_atoi(argv[index]));
		tmp->next = head;
		head = tmp;
		index++;
	}
	printlist(head);
}

struct s_node	*new_node(int value)
{
	struct s_node	*stack;

	(void) value;
	stack = malloc(sizeof(stack));
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	printlist(t_node *head)
{
	t_node	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}
