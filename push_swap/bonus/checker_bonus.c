/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:08:35 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/22 12:01:30 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_same(char *line, char *cmd)
{
	if (ft_strncmp(line, cmd, ft_strlen(line) - 1) == 0
		&& ft_strlen(line) == ft_strlen(cmd) + 1)
		return (1);
	return (0);
}

void	check_cmd_unit(char *line, t_stack **a, t_stack **b)
{
	if (is_same(line, "ra"))
		execute_r(a);
	else if (is_same(line, "rb"))
		execute_r(b);
	else if (is_same(line, "rr"))
		execute_r_both(a, b);
	else if (is_same(line, "rra"))
		execute_rr(a);
	else if (is_same(line, "rrb"))
		execute_rr(b);
	else if (is_same(line, "rrr"))
		execute_rr_both(a, b);
	else if (is_same(line, "pa"))
		execute_p(a, b);
	else if (is_same(line, "pb"))
		execute_p(b, a);
	else if (is_same(line, "sa"))
		execute_s(a);
	else if (is_same(line, "sb"))
		execute_s(b);
	else if (is_same(line, "ss"))
		execute_s_both(a, b);
	else
		show_error("Error\n");
}

void	execute_cmd_set(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_cmd_unit(line, a, b);
		free(line);
	}
}

void	check_sorted(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size != 0)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	temp = a->top;
	while (1)
	{
		if (temp->idx > temp->next->idx)
		{
			ft_putstr_fd("KO\n", 1);
			exit(0);
		}
		temp = temp->next;
		if (temp->next->idx == a->top->idx)
			break ;
	}
	ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stat	stat;
	int		*sorted_list;

	if (argc == 1)
		return (0);
	if (!check_right_cmd(argv))
		show_error("Error\n");
	sort(&sorted_list, argc - 1, argv);
	check_same_number(sorted_list, argc);
	get_pivot(&stat, sorted_list, argc - 1);
	init_stack(&a, &b, argv, &stat);
	execute_cmd_set(&a, &b);
	check_sorted(a, b);
}
