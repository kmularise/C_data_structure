/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:39:06 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 19:57:14 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_final_sort(t_stack **a, t_stack **b)
{
	show_p(a, b, 'a');
	show_p(a, b, 'a');
	if ((*a)->top->idx >= 3)
	{
		while ((*a)->top->idx != 0)
			show_r(a, b, 'a');
	}
	else
	{
		while ((*a)->top->idx != 0)
			show_rr(a, b, 'a');
	}
}
