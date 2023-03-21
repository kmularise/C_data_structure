/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:28:58 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:32:12 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_few_input_case(t_stack **a, t_stack **b, t_stat *stat)
{
	if (stat->count == 2)
		do_two_element(a, b);
	if (stat->count == 3)
		do_three_element(a, b, 0);
	if (stat->count == 4)
		do_four_element(a, b);
	if (stat->count == 5)
		do_five_element(a, b);
	exit(0);
}

void	do_two_element(t_stack **a, t_stack **b)
{
	if ((*a)->top->idx == 1)
		show_s(a, b, 'a');
}

void	do_three_element(t_stack **a, t_stack **b, int opt)
{
	if ((*a)->top->prev->idx == (2 + opt) % 5
		&& (*a)->top->idx == (1 + opt) % 5)
		show_s(a, b, 'a');
	if ((*a)->top->prev->idx == opt && (*a)->top->idx == (2 + opt) % 5)
		show_s(a, b, 'a');
	if ((*a)->top->prev->idx == (1 + opt) % 5 && (*a)->top->idx == opt)
		show_s(a, b, 'a');
	if ((*a)->top->prev->idx == opt && (*a)->top->idx == (1 + opt) % 5)
		show_rr(a, b, 'a');
	if ((*a)->top->prev->idx == (1 + opt) % 5
		&& (*a)->top->idx == (2 + opt) % 5)
		show_r(a, b, 'a');
}

void	do_four_element(t_stack **a, t_stack **b)
{
	if ((*a)->top->prev->idx == 0)
		show_rr(a, b, 'a');
	if ((*a)->top->next->idx == 0)
		show_r(a, b, 'a');
	if ((*a)->top->prev->prev->idx == 0)
	{
		show_r(a, b, 'a');
		show_r(a, b, 'a');
	}
	if ((*a)->top->idx == 0)
	{
		show_p(a, b, 'b');
		do_three_element(a, b, 1);
		show_p(a, b, 'a');
	}
}

void	do_five_element(t_stack **a, t_stack **b)
{
	int	candidates[2];

	show_p(a, b, 'b');
	candidates[0] = (*b)->top->idx - 1;
	candidates[1] = (*b)->top->idx + 1;
	if ((*a)->top->idx == candidates[0] || (*a)->top->idx == candidates[1])
		;
	else if ((*a)->top->next->idx == candidates[0]
		|| (*a)->top->next->idx == candidates[1])
		show_r(a, b, 'a');
	else if ((*a)->top->prev->idx == candidates[0]
		|| (*a)->top->prev->idx == candidates[1])
		show_rr(a, b, 'a');
	else
	{
		show_r(a, b, 'a');
		show_r(a, b, 'a');
	}
	show_p(a, b, 'b');
	if ((*b)->top->idx < (*b)->top->prev->idx)
		show_s(a, b, 'b');
	do_three_element(a, b, ((*b)->top->idx + 1) % 5);
	make_final_sort(a, b);
}
