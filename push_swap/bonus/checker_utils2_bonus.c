/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:51:14 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/22 09:59:28 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	quick_sort(int *list, int first, int last)
{
	t_info	info;

	info.left = first;
	info.right = last;
	info.pivot = list[(first + last) / 2];
	while (info.left <= info.right)
	{
		while (list[info.left] < info.pivot)
			info.left++;
		while (list[info.right] > info.pivot)
			info.right--;
		if (info.left <= info.right)
		{
			info.temp = list[info.left];
			list[info.left] = list[info.right];
			list[info.right] = info.temp;
			info.left++;
			info.right--;
		}
	}
	if (info.right > first)
		quick_sort(list, first, info.right);
	if (info.left < last)
		quick_sort(list, info.left, last);
}

void	sort(int **sorted_list, int count, char **argv)
{
	int	i;

	(*sorted_list) = malloc(sizeof(int) * count);
	i = 1;
	while (argv[i])
	{
		(*sorted_list)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	quick_sort((*sorted_list), 0, count -1);
}

void	get_pivot(t_stat *stat, int *list, int count)
{
	stat->pivot1 = (count - 1) / 3;
	stat->pivot2 = (2 * count - 2) / 3;
	stat->count = count;
	stat->max = list[count - 1];
	stat->list = list;
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
