#include "push_swap.h"

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
		if (temp->idx > idx && (temp->idx > temp->prev->idx && idx > temp->prev->idx))
		{
			// printf("zzz %d %d %d count %d\n", temp->idx, idx, temp ->prev->idx, count);
			return (count);
		}
		if (idx < temp->idx && temp->idx < temp->prev->idx)
			return (count);
		temp = temp->next;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}

// int get_local_max(t_node *a_top)
// {
// 	t_node *temp;
// 	int	max;
// 	max = -1;
// 	while (1)
// 	{
// 		if (temp->idx > temp->next->idx > temp->next->idx > temp->prev->idx)
// 			return (temp);
// 		temp = temp->prev;
// 		if (temp->idx == a_top->idx)
// 			break ;
// 	}
// }

int find_count_rra(t_node *a_top, int idx)
{
	t_node	*temp;
	t_node	*a_bottom;
	int	count;

	temp = a_top;
	a_bottom = a_top->prev;
	count = 0;
	while (1)
	{
		if (idx == 29)
		{
			printf("top :%d\n", temp->idx);
			printf("bottom :%d\n\n", temp->prev->idx);
		}

		if (temp->idx > temp->next->idx && temp->next->idx > temp->prev->idx)
		{
			printf("dfsdfsdfsdfsd\n");
			if (temp->idx > idx)
				return (count);
		}
		if (temp->next->idx > temp->idx && temp->idx > temp->prev->idx)
		{
			if (temp->idx > idx && idx > temp->prev->idx)
				return (count);
		}
		// if (temp->idx > idx && idx > temp->prev->idx)
		// 	return (count);
		// if (temp->idx > idx && (temp->idx > temp->prev->idx && idx > temp->prev->idx))
		// {
		// 	// if (idx == 29)
		// 	// 	printf("zzz %d %d %d count %d\n", temp->idx, idx, temp ->prev->idx, count);
		// 	return (count);
		// }
		// if (idx < temp->idx && temp->idx < temp->prev->idx)
		// {
		// 	// if (idx == 29)
		// 	// 	printf("zzz %d %d %d count %d\n", temp->idx, idx, temp ->prev->idx, count);
		// 	return (count);
		// }
		temp = temp->prev;
		count++;
		if (temp->idx == a_top->idx)
			break ;
	}
	return (count);
}

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