#include "push_swap.h"

void	do_two_element(t_stack **a, t_stack **b)
{
	if ((*a)->top->data > ((*a)->top->next->data))
		show_s(a, b, 'a');
}

void	do_three_element(t_stack **a, t_stack **b)
{
	if ((*a)->top->prev->idx > (*a)->top->next->idx 
		&& (*a)->top->prev->idx > (*a)->top->idx)
	{
		if ((*a)->top->idx > (*a)->top->next->idx)
			show_s(a, b, 'a');
	}
	else //1 2 3 1 3 2, 2 3 1 2 1 3 
	{
		if ((*a)->top->prev->idx < (*a)->top->next->idx)
		{
			if ((*a)->top->idx > (*a)->top->next->idx)//1 2 3
				show_s(a, b, 'a');
			show_r(a, b, 'a');
		}

	}
}