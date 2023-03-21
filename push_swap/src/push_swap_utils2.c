/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:41:50 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:20:45 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	i = 0;
	while (++i < argc - 1)
	{
		if (ft_atoi(argv[i]) >= ft_atoi(argv[i + 1]))
			return (0);
	}
	return (1);
}

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

void	check_same_number(int *sorted_list, int argc)
{
	int	count;
	int	i;

	count = argc - 1;
	i = -1;
	while (++i < count - 1)
	{
		if (sorted_list[i] == sorted_list[i + 1])
			show_error("smae Error\n");
	}
}
