/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:21:42 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/21 21:00:26 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr_index(t_node *stack_a, t_node *head) // zu get_index_nbr andern
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

void	printlist(t_node *head) // loeschen am ende
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
