/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:06:37 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/01 11:22:05 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*head;

	head = NULL;
	head = parser(argc, argv, head);
	printlist(head);
	sawp_stack_a(&head);
	printlist(head);
	sawp_stack_a(&head);
	printlist(head);
	rotate_stack_a(&head);
	printlist(head);
	return (0);
}
