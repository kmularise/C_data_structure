/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:32:47 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/22 09:53:04 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	show_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

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

void	check_same_number(int *sorted_list, int argc)
{
	int	count;
	int	i;

	count = argc - 1;
	i = -1;
	while (++i < count - 1)
	{
		if (sorted_list[i] == sorted_list[i + 1])
			show_error("Error\n");
	}
}
