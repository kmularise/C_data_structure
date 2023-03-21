/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:42:27 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:22:51 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	binary_search(int value, int start, int end, int *list)
{
	int	mid;

	if (start > end)
		return (-1);
	mid = (start + end) / 2;
	if (value == list[mid])
		return (mid);
	if (value < list[mid])
		return (binary_search(value, start, mid - 1, list));
	return (binary_search(value, mid + 1, end, list));
}

int	get_index(int value, int *list, int count)
{
	return (binary_search(value, 0, count - 1, list));
}

int	min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

void	get_min_node_info(t_node *a_top, t_node *b_top, t_node *temp, int *info)
{
	int	count_ra;
	int	count_rra;
	int	count_rb;
	int	count_rrb;

	count_ra = find_count_ra(a_top, temp->idx);
	count_rra = find_count_rra(a_top, temp->idx);
	count_rb = find_count_rb(b_top, temp->idx);
	count_rrb = find_count_rrb(b_top, temp->idx);
	if (min(count_ra, count_rra) == count_ra)
		info[0] = RA;
	else
		info[0] = RRA;
	info[1] = min(count_ra, count_rra);
	if (min(count_rb, count_rrb) == count_rb)
		info[2] = RB;
	else
		info[2] = RRB;
	info[3] = min(count_rb, count_rrb);
}
