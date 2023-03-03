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
	// start = (*a)->top->data;
	printf("pivots %d %d\n", stat->pivot1, stat->pivot2);
	// printf("top %d\n", ((*a)->top)->data);
	// printf("size %d\n", (*b)->size);
	while (i < stat->count)
	// while (i < 1)
	{
		// show_r(a, b, 'a');
		if ((*a)->top->idx > stat->pivot2)
			show_r(a, b, 'a');
		else if ((*a)->top->idx <= stat->pivot1)
		{
			show_p(a, b, 'b');
			show_r(a, b, 'b');
		}
		else
			show_p(a, b, 'b');
		i++;
	}
	// printf("size %d\n", (*b)->size);
	// printf("size %d\n", (*a)->size);
	// printf("size %d\n", (*b)->size);
	while ((*a)->size > 2)
	{
		show_p(a, b, 'b');
	}
	do_two_element(a, b);
	// // show_p(a, b, 'a');
	// i = 0;
	// // while ((*b)->size >0)
	// // int count;
	// while ((*b)->top->data > stat->pivot2)
	// {
	// 	if ((*b)->top->data == stat->max)
	// 	{
	// 		show_p(a,b, 'a');
	// 	}
	// 	else{
	// 		while ((*b)->top->data >= (*a)->top->data)
	// 		{
	// 			show_r(a, b, 'a');
	// 		}
	// 		if ((*b)->top->data < (*a)->top->data)
	// 		{
	// 			show_p(a, b, 'a');
	// 		}
	// 		i++;
	// 	}
	// }


}

// int	find_min_node_idx(t_node *a_top, t_node *b_top)
// {
// 	int	count_r_a;
// 	int	count_r_b;



// }

int	find_count_rb(t_node *a_top, int idx)
{
	t_node *temp;
	int count;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp->next;
		count++;
	}
	return (-1);
}

int	find_count_rrb(t_node *a_top, int idx)
{
	t_node *temp;
	int count;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp->prev;
		count++;
	}
	return (-1);
}

int	find_count_b()
{
	t_node *temp;
}