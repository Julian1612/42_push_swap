/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/04 18:02:00 by jschneid         ###   ########.fr       */
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
	// printf("S: ");
	// printlist(stack_a);
	// printf("S: ");
	// printlist(stack_b);
	// push_to_stack_b(&stack_a, &stack_b);
	// printf("A: ");
	// printlist(stack_a);
	// printf("B: ");
	// printlist(stack_b);
	// push_to_stack_b(&stack_a, &stack_b);
	// printf("A: ");
	// printlist(stack_a);
	// printf("B: ");
	// printlist(stack_b);
	// swap_stack_b(&stack_b);
	// printf("A: ");
	// printlist(stack_a);
	// printf("B: ");
	// printlist(stack_b);
	swap_stack_a(&stack_a);
	push_to_stack_b(&stack_a, &stack_b);
	push_to_stack_b(&stack_a, &stack_b);
	push_to_stack_b(&stack_a, &stack_b);
	rotate_stack_a(&stack_a);
	rotate_stack_a(&stack_b);
	reverse_rotate_stack_a(&stack_a);
	reverse_rotate_stack_a(&stack_b);
	swap_stack_a(&stack_a);
	push_to_stack_b(&stack_b, &stack_a);
	push_to_stack_b(&stack_b, &stack_a);
	push_to_stack_b(&stack_b, &stack_a);
	printf("A: ");
	printlist(stack_a);
	printf("B: ");
	printlist(stack_b);
	// system("leaks push_swap");
	return (0);
}
