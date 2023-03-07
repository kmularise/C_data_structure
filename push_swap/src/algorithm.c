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
	while ((*a)->size > 0)
	{
		show_p(a, b, 'b');
	}
}

void	select_best_idx(t_stack **a, t_stack **b, t_stat *stat)
{
	t_node	*temp;
	int		answer;
	int		min_value;
	int		min_idx;

	min_value = 2147483647;
	min_idx = -1;
	temp = (*a)->top;
	// while (temp->idx >= stat->pivot2)
	while (1)
	{
		answer = min(find_count_ra((*a)->top, temp->idx), find_count_rra((*a)->top, temp->idx));
		answer += min(find_count_rb((*b)->top, temp->idx), find_count_rrb((*b)->top, temp->idx));
		if (min_value > answer)
			min_idx = temp->idx;
		temp = temp->next;
		if (temp->idx == (*a)->top->idx)
			break ;
	}
	// printf("%d ")
	
}
