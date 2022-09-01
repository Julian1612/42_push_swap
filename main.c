/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/01 12:43:48 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*head;

	head = NULL;
	head = parser(argc, argv, head);
	// printf("List at beginning\n");
	printlist(head);
	// swap_stack_a(&head);
	// printf("Swaped the first two elemnts of stack A\n");
	// printlist(head);
	// rotate_stack_a(&head);
	// printf("Rotate stack A\n");
	// printlist(head);
	reverse_rotate_stack_a(&head);
	printf("Reverse rotate stack_A\n");
	printlist(head);
	reverse_rotate_stack_a(&head);
	printf("Reverse rotate stack_A\n");
	printlist(head);
	reverse_rotate_stack_a(&head);
	printf("Reverse rotate stack_A\n");
	printlist(head);
	reverse_rotate_stack_a(&head);
	printf("Reverse rotate stack_A\n");
	printlist(head);
	reverse_rotate_stack_a(&head);
	printf("Reverse rotate stack_A\n");
	printlist(head);
	return (0);
}
