/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/01 12:39:20 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*parser(int argc, char **argv, t_node *head)
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

struct s_node	*new_node(int value)
{
	struct s_node	*stack;

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
