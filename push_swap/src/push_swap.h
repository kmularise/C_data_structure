/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:43:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:54:11 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define RA 0
# define RRA 1
# define RB 0
# define RRB 1

typedef struct s_stat{
	int	pivot1;
	int	pivot2;
	int	max;
	int	min;
	int	count;
	int	*list;
}	t_stat;

typedef struct s_node {
	int				data;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int				size;
	struct s_node	*top;
}	t_stack;

typedef struct s_info
{
	int	left;
	int	right;
	int	pivot;
	int	temp;
}	t_info;

t_node	*create_node(int data);
void	push_node(t_node **head, t_node *node);
void	print_list(t_node **head);
void	print_list_reverse(t_node **head);
void	pop_node(t_node **head);
void	rotate_list(t_node **head, int count);
void	print_list_reverse_idx(t_node **head);

void	execute_s(t_stack **stack);
void	execute_p(t_stack **push_stack, t_stack **pop_stack);
void	execute_r(t_stack **stack);
void	execute_rr(t_stack **stack);

void	show_s(t_stack **a, t_stack **b, char idx);
void	show_p(t_stack **a, t_stack **b, char idx);
void	show_r(t_stack **a, t_stack **b, char idx);
void	show_rr(t_stack **a, t_stack **b, char idx);

void	show_error(char *message);
int		binary_search(int value, int start, int end, int *list);
int		get_index(int value, int *list, int count);
int		min(int num1, int num2);

void	get_min_node_info(t_node *a_top, t_node *b_top,
			t_node *temp, int *info);
void	do_two_element(t_stack **a, t_stack **b);
void	do_partition(t_stack **a, t_stack **b, t_stat *stat);
int		*select_best_idx(t_stack **a, t_stack **b);
void	do_sorting(t_stack **a, t_stack **b);

int		find_count_rb(t_node *b_top, int idx);
int		find_count_rrb(t_node *b_top, int idx);
int		find_count_ra(t_node *a_top, int idx);
int		find_count_rra(t_node *a_top, int idx);
void	get_last_member_max(t_stack **a, t_stack **b);

int		is_sorted(int argc, char **argv);

void	handle_few_input_case(t_stack **a, t_stack **b, t_stat *stat);
void	do_two_element(t_stack **a, t_stack **b);
void	do_three_element(t_stack **a, t_stack **b, int opt);
void	do_four_element(t_stack **a, t_stack **b);
void	do_five_element(t_stack **a, t_stack **b);
int		get_last_ra_count(t_stack **a);
int		get_last_rra_count(t_stack **a);
void	make_final_sort(t_stack **a, t_stack **b);
void	sort(int **sorted_list, int count, char **argv);
void	check_same_number(int *sorted_list, int argc);

#endif