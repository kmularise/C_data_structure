#include "push_swap.h"

void	do_two_element(t_stack **a, t_stack **b)
{
	if ((*a)->top->data > ((*a)->top->next->data))
		show_s(a, b, 'a');
}