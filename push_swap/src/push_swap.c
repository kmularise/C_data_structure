/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:49:06 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:33:38 by yuikim           ###   ########.fr       */
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

void	get_pivot(t_stat *stat, int *list, int count)
{
	stat->pivot1 = (count - 1) / 3;
	stat->pivot2 = (2 * count - 2) / 3;
	stat->count = count;
	stat->max = list[count - 1];
	stat->list = list;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stat	stat;
	int		*sorted_list;

	if (argc == 1)
		show_error("Error\n");
	if (!check_right_cmd(argv))
		show_error("Error\n");
	if (is_sorted(argc, argv))
		exit(0);
	sort(&sorted_list, argc - 1, argv);
	check_same_number(sorted_list, argc);
	get_pivot(&stat, sorted_list, argc - 1);
	init_stack(&a, &b, argv, &stat);
	if (stat.count <= 5)
		handle_few_input_case(&a, &b, &stat);
	do_partition(&a, &b, &stat);
	do_sorting(&a, &b);
	get_last_member_max(&a, &b);
}
