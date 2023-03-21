/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:49:06 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 15:14:58 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_right_cmd(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!is_number(argv[i]))
			return (0);
	return (1);
}

void	init_stack(t_stack **a, t_stack **b, char **argv, t_stat *stat)
{
	int		i;
	t_node	*temp;

	i = stat->count;
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->top = NULL;
	(*b)->size = 0;
	(*a)->top = create_node(ft_atoi(argv[i]));
	(*a)->top->idx = get_index(ft_atoi(argv[i]), stat->list, stat->count);
	(*a)->size = 1;
	while (--i > 0)
	{
		temp = create_node(ft_atoi(argv[i]));
		temp->idx = get_index(ft_atoi(argv[i]), stat->list, stat->count);
		push_node(&((*a)->top), temp);
		(*a)->size += 1;
	}
}

void quick_sort(int *list, int first, int last)
{
	int	left;
	int	right;
	int	pivot;
	int	temp;

	left = first;
	right = last;
	pivot = list[(first + last) / 2];
	while (1)
	{
		while (list[left] < pivot)
			left++;
		while (list[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = list[left];
			list[left] = list[right];
			list[right] = temp;
			left++;
			right--;
		}
		if (left > right)
			break ;
	}
	if (right > first)
		quick_sort(list, first, right);
	if (left < last)
		quick_sort(list, left, last);
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
	// for (i=0; i < count; i++){
	// 	printf("%d ", (*sorted_list)[i]);
	// }
}

void	get_pivot(t_stat *stat, int *list, int count)
{
	stat->pivot1 = (count - 1) / 3;
	stat->pivot2 = (2 * count - 2) / 3;
	stat->count = count;
	stat->max = list[count - 1];
	stat->list = list;

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

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stat stat;
	int		*sorted_list;

	if (argc == 1)
		show_error("Error\n");
	if (!check_right_cmd(argv))
		show_error("Error\n");
	if(is_sorted(argc, argv))
		exit(0);
	sort(&sorted_list, argc - 1, argv);
	check_same_number(sorted_list, argc);
	get_pivot(&stat, sorted_list, argc - 1);
	init_stack(&a, &b, argv, &stat);

	if (stat.count <= 5)
		handle_few_input_case(&a, &b, &stat);
	// handle_general_input_case();
	do_partition(&a, &b, &stat);
	do_sorting(&a, &b, &stat);
	get_last_member_max(&a, &b, &stat);
	// print_list_reverse_idx(&(a->top));
	// print_list_reverse_idx(&(b->top));

	// system("leaks a.out");
}