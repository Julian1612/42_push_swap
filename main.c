/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/22 11:00:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		chunk_size;
	int		chunk;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parser(argc, argv, stack_a);
	stack_a = index_list(stack_a);
	chunk = get_chunk_size(&stack_a);
	chunk_size = chunk;
	// if (list_size(stack_a) == 3)
	// {
	// 	sort_three_elemens(stack_a);
	// 	return (0);
	// }
	if (list_size(stack_a) == 2)
	{
		swap_a(&stack_a);
		return (0);
	}
	sort_five_elements(&stack_a, &stack_b);
	// pre_sort_stack(&stack_a, &stack_b, chunk, chunk_size);
	// sort_stack(&stack_a, &stack_b);
	free_list(stack_a);
	// system("leaks push_swap");
	return (0);
}

void	free_list(t_node *list)
{
	t_node	*tmp;

	tmp = NULL;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
