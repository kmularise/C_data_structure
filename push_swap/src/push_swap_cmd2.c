# include "push_swap.h"

void	show_s(t_stack **a, t_stack **b, char idx) {
	if (idx == 's')
	{
		execute_s(a);
		execute_s(b);
	}
	else if (idx == 'a')
		execute_s(a);
	else if (idx == 'b')
		execute_s(b);
	printf("s%c\n", idx);
}

void	show_p(t_stack **a, t_stack **b, char idx) {
	if (idx == 'a')
		execute_p(a, b);
	else if (idx == 'b')
		execute_p(b, a);
	printf("p%c\n", idx);
}

void	show_r(t_stack **a, t_stack **b, char idx) {
	if (idx == 'a')
		execute_r(a);
	else if (idx == 'b')
		execute_r(b);
	else if (idx == 'r')
	{
		execute_r(a);
		execute_r(b);
	}
	printf("r%c\n", idx);
}

void	show_rr(t_stack **a, t_stack **b, char idx) {
	if (idx == 'a')
		execute_rr(a);
	else if (idx == 'b')
		execute_rr(b);
	else if (idx == 'r')
	{
		execute_rr(a);
		execute_rr(b);
	}
	printf("rr%c\n", idx);
}