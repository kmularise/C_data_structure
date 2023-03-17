/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:44:40 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/17 18:43:45 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void	make_setting(t_stat *stat)
{
	stat->pivot1 = (stat->count - 1) / 3;
	stat->pivot2 = (2 * stat->count - 2) / 3;

}

void	do_partition(t_stack **a, t_stack **b, t_stat *stat)
{
	int	i;

	i = 0;
	printf("pivots %d %d\n", stat->pivot1, stat->pivot2);
	while (i < stat->count )
	{
		if ((*a)->top->idx >= stat->pivot2)
			show_r(a, b, 'a');
		else if ((*a)->top->idx < stat->pivot1)
		{
			show_p(a, b, 'b');
			show_r(a, b, 'b');
		}
		else
			show_p(a, b, 'b');
		i++;
	}
	while ((*a)->size > 2)
	{
		show_p(a, b, 'b');
	}
}

int	*select_best_idx(t_stack **a, t_stack **b, t_stat *stat)
{
	t_node	*temp;
	int		info[4];
	int		min_value;
	int		*min_idx;
	int		i; 

	min_value = 2147483647;
	min_idx = malloc(sizeof(int) * 5);
	min_idx[0] = -1;
	temp = (*b)->top;
	// while (temp->idx >= stat->pivot2)
	while (1)
	{
		get_min_node_info((*a)->top, (*b)->top, temp, info);
		if (min_value > info[1] + info[3])
		{
			min_value = info[1] + info[3];
			min_idx[0] = temp->idx;
			i = -1;
			while (++i < 4)
				min_idx[i + 1] = info[i];  
		}
		temp = temp->next;
		if (temp->idx == (*b)->top->idx)
			break ;
		i++;
	}
	return (min_idx);
}

void	do_sorting(t_stack **a, t_stack **b, t_stat *stat)
{
	int *min_idx;
	int j = 0;
	int i;
	while ((*b)->size > 0 && j < 2)
	{
		min_idx = select_best_idx(a, b, stat);
		printf("min %d\n", min_idx[0]);
		i = -1;
		while (++i < min_idx[4])
		{
			if (min_idx[3] == RB)
				show_r(a, b, 'b');
			else
				show_rr(a, b, 'b');
		}
		i = -1;
		while (++i < min_idx[2])
		{
			if (min_idx[0] == RA)
				show_r(a, b, 'a');
			else
				show_rr(a, b, 'a');
		}
		if (j == 0)
			show_p(a, b, 'a');
		free(min_idx);
		j++;
	}
}