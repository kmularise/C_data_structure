/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:42:27 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/07 17:34:58 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//show error
void	show_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	binary_search(int value, int start, int end, int *list)
{
	int	mid;

	if (start > end)
		return (-1) ;
	mid = (start + end) / 2;
	if (value == list[mid])
		return mid;
	if (value < list[mid])
		return binary_search(value, start, mid - 1, list);
	return binary_search(value, mid + 1, end, list);
}

int	get_index(int value, int *list, int count)
{
	return (binary_search(value, 0, count - 1, list));
}

int min (int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}