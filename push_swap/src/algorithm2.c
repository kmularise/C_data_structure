/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:18:10 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 19:22:01 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_ra_count(t_stack **a)
{
	int		count;
	t_node	*temp;

	temp = (*a)->top;
	count = 0;
	while (1)
	{
		if (temp->idx == 0)
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	get_last_rra_count(t_stack **a)
{
	int		count;
	t_node	*temp;

	temp = (*a)->top;
	count = 0;
	while (1)
	{
		if (temp->idx == 0)
			break ;
		count++;
		temp = temp->prev;
	}
	return (count);
}
