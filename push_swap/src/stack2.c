/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:23:04 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_node **head, int count)
{
	if (count > 0)
	{
		while (--count != -1)
			*head = (*head)->next;
	}
	else if (count < 0)
	{
		while (++count != 1)
			*head = (*head)->prev;
	}
}

void	print_list_reverse_idx(t_node **head)
{
	t_node	*curr_node;

	if (!(*head))
	{
		return ;
	}
	curr_node = (*head)->prev;
	while (curr_node != *head)
	{
		printf("%d ", curr_node->idx);
		curr_node = curr_node->prev;
	}
	printf("%d\n", curr_node->idx);
}
