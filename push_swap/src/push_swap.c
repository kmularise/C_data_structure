/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:49:06 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/02 21:54:44 by yuikim           ###   ########.fr       */
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
void	init_stack(t_stack **a, t_stack **b, char **argv)
{
	int		i;
	t_node	*temp;

	i = 1;
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->top = NULL;
	(*b)->size = 0;
	(*a)->top = create_node(ft_atoi(argv[i]));
	(*a)->size = 1;
	while (argv[++i])
	{
		temp = create_node(ft_atoi(argv[i]));
		push_node(&((*a)->top), temp);
		(*a)->size += 1;
	}

}

void	show_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
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
		printf("%d %d \n", i, ft_atoi(argv[i]));
		i++;
	}
	quick_sort((*sorted_list), 0, count -1);
	for (i=0; i < count; i++){
		printf("%d ", (*sorted_list)[i]);
	}
}

int main(int argc, char **argv)
{
	// t_stack *a;
	// t_stack *b;
	int	*sorted_list;

	if (argc == 1)
		show_error("Error\n");
	if (!check_right_cmd(argv))
		show_error("Error\n");
	sort(&sorted_list, argc - 1, argv);
	//min ~ pivot1 설정
	//pivot1 ~ pivot2 설정 가능
	//pivot2 ~max 설정 가능



	// init_stack(&a, &b, argv);
	// print_list_reverse(&(a->top));
	// execute_s(&a);
	// print_list_reverse(&(a->top));
	// execute_p(&b, &a);
	// print_list_reverse(&(a->top));
	// print_list_reverse(&(b->top));
	// execute_rr(&a);
	// print_list_reverse(&(a->top));

	// system("leaks a.out");
}