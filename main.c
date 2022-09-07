/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/07 15:52:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parser(argc, argv, stack_a);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	swap_a(&stack_a);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_b(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_b(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_b(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	rotate_stacks(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	reverse_rotate_satcks(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	swap_a(&stack_a);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_a(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_a(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	push_a(&stack_a, &stack_b);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	return (0);
}
