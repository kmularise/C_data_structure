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

int	find_count_rb(t_node *b_top, int idx)
{
	t_node *temp;
	int	count;

	temp = b_top;
	count = 0;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp = temp->next;
		count++;
	}
	return (-1);
}

int	find_count_rrb(t_node *b_top, int idx)
{
	t_node	*temp;
	int		count;
	
	temp = b_top;
	count = 0;
	while (1)
	{
		if (temp->idx == idx)
			return (count);
		temp = temp->prev;
		count++;
	}
	return (-1);
}

// int	find_count_rra(t_node *a_top, int idx)
// {
// 	t_node	*temp;
// 	t_node	*a_bottom;
// 	int	count;

// 	temp = a_top;
// 	a_bottom = a_top->prev;
// 	count = 0;
// 	if (a_bottom->idx > a_top->idx)//정렬이 되어 있는 상태
// 	{
// 		while(1)
// 		{
// 			if (a_bottom->idx > idx)
// 				return (count);
// 			temp = temp->prev;
// 			count++;
// 		}
// 	}
// 	else//완전 정렬은 안되어 있는 상태
// 	{
// 		while (1)
// 		{
// 			if (a_bottom->idx < idx && idx < a_top->idx)
// 				return (count);
// 			temp = temp->prev;
// 			count++;
// 		}
// 	}
// 	return (-1);
// }

// int find_count_rra(t_node *a_top, int idx)
// {
// 	t
// }

//왜 해결이 안되냐
int	find_count_rra(t_node *a_top, int idx)
{
	t_node	*temp;
	t_node	*a_bottom;
	int	count;

	temp = a_top;
	a_bottom = a_top->prev;
	count = 0;
	while (1)
	{
		if (temp->idx < idx && idx < temp->prev->idx)
			return (count);
		if (idx < temp->prev->idx && temp->idx < temp->prev->idx)
			return (count);
		temp = temp->prev;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}

int find_count_ra(t_node *a_top, int idx)
{
	t_node	*temp;
	t_node	*a_bottom;
	int	count;

	temp = a_top;
	a_bottom = a_top->prev;
	count = 0;
	while (1)
	{
		if (a_top->idx < idx && idx < a_bottom->idx)
			return (count);
		if (idx < a_bottom->idx && a_top->idx < a_bottom->idx)
			return (count);
		temp = temp->next;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}