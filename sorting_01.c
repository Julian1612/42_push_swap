/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:38 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/20 15:14:20 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*smallest_element_top(t_node *head, int chunk_start, int chunk_end) // pointer rein meddeln
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	smallest_element = head;
	index = 0;
	while (index < (size_list / 2))
	{
		if (head->data >= chunk_start && head->data <= chunk_end)
		{
			smallest_element = head;
			return (smallest_element);
		}
		head = head->next;
		index++;
	}
	return (smallest_element);
}

t_node	*smallest_element_bottom(t_node *head, int chunk_start, int chunk_end)
{
	int		index;
	int		size_list;
	t_node	*smallest_element;

	size_list = list_size(head);
	index = 0;
	while (index < (size_list / 2))
	{
		head = head->next;
		index++;
	}
	smallest_element = head;
	while (head != NULL)
	{
		if (head->data >= chunk_start && head->data <= chunk_end)
			smallest_element = head;
		head = head->next;
		index++;
	}
	return (smallest_element);
}

t_node	*largest_element_list(t_node *head) // name andern
{
	int		index;
	int		size_list;
	t_node	*largest_element;

	size_list = list_size(head);
	largest_element = head;
	index = 0;
	while (index < size_list)
	{
		if (largest_element->data < head->data)
			largest_element = head;
		head = head->next;
		index++;
	}
	return (largest_element);
}

int	moves_top(t_node *head, t_node *top)
{
	int	counter;

	counter = 0;
	while (head != top)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	moves_buttom(t_node *buttom)
{
	int	counter;

	counter = 0;
	while (buttom != NULL)
	{
		counter++;
		buttom = buttom->next;
	}
	return (counter);
}
