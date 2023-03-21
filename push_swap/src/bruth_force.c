/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruth_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:23:39 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 19:28:29 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_count_ra(t_node *a_top, int idx)
{
	t_node	*temp;
	t_node	*a_bottom;
	int		count;

	temp = a_top;
	a_bottom = a_top->prev;
	count = 0;
	while (1)
	{
		if (idx > temp->prev->idx && temp->prev->idx > temp->idx)
			return (count);
		if (temp->idx > idx && (temp->idx > temp->prev->idx
				&& idx > temp->prev->idx))
			return (count);
		if (idx < temp->idx && temp->idx < temp->prev->idx)
			return (count);
		temp = temp->next;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}

int	find_count_rra(t_node *a_top, int idx)
{
	t_node	*temp;
	t_node	*a_bottom;
	int		count;

	temp = a_top;
	a_bottom = a_top->prev;
	count = 0;
	while (1)
	{
		if (idx > temp->prev->idx && temp->prev->idx > temp->idx)
			return (count);
		if (temp->idx > idx && (temp->idx > temp->prev->idx
				&& idx > temp->prev->idx))
			return (count);
		if (idx < temp->idx && temp->idx < temp->prev->idx)
			return (count);
		temp = temp->prev;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}

int	find_count_rb(t_node *b_top, int idx)
{
	t_node	*temp;
	int		count;

	temp = b_top;
	count = 0;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp = temp->next;
		count++;
	}
	return (-1);
}

int	find_count_rrb(t_node *b_top, int idx)
{
	t_node	*temp;
	int		count;

	temp = b_top;
	count = 0;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp = temp->prev;
		count++;
	}
	return (-1);
}
