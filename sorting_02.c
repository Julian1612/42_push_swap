/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:03:20 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/20 08:43:31 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_check(t_node *head, int chunk_start, int chunk_end)
{
	while (head != NULL)
	{
		if (head->data >= chunk_start && head->data <= chunk_end)
			return (1);
		head = head->next;
	}
	return (0);
}
