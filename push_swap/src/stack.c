/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/07 17:05:39 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	push_node(t_node **head, t_node *node)
{
	t_node	*current_node;

	if (!(*head))
	{
		*head = node;
		return ;
	}
	current_node = *head;
	current_node->prev = node;
	while (current_node->next != *head)
		current_node = current_node->next;
	current_node->next = node;
	node->next = *head;
	*head = node;
	(*head)->prev = current_node;
}

void	pop_node(t_node **head)
{
	t_node	*current_node;
	t_node	*next_node;
	t_node	*prev_node;

	if (!(*head))
		return ;
	current_node = *head;
	next_node = current_node->next;
	if (current_node == next_node)
		*head = NULL;
	else
	{
		prev_node = current_node->prev;
		*head = next_node;
		(*head)->prev = current_node->prev;
		prev_node->next = current_node->next;
	}
	free(current_node);
}

void	print_list(t_node **head)
{
	t_node	*curr_node;

	if (!(*head))
	{
		return ;
	}
	curr_node = *head;
	while (curr_node->next != *head)
	{
		printf("%d ", curr_node->data);
		curr_node = curr_node->next;
	}
	printf("%d\n", curr_node->data);
}

void	print_list_reverse(t_node **head)
{
	t_node	*curr_node;

	if (!(*head))
	{
		return ;
	}
	curr_node = (*head)->prev;
	while (curr_node != *head)
	{
		printf("%d ", curr_node->data);
		curr_node = curr_node->prev;
	}
	printf("%d\n", curr_node->data);
}
