/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/01 13:39:27 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parser(int argc, char **argv, t_node *head)
{
	int		index;
	t_node	*tmp;

	index = argc - 1;
	while (index > 0)
	{
		tmp = new_node(ft_atoi(argv[index]));
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
