/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/02/20 21:19:00 by yuikim           ###   ########.fr       */
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
