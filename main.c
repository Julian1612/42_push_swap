/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/28 18:37:05 by jschneid         ###   ########.fr       */
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
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = index_list(stack_a);
	chunk = get_chunk_size(&stack_a);
	chunk_size = chunk;
	sorting(&stack_a, &stack_b, chunk, chunk_size);
	// printf("kek%ikek\n", list_size(stack_a));
	free_list(stack_a);
	return (0);
}
