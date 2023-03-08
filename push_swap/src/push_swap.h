/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:43:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/08 10:43:19 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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
	int *list;
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
int		min (int num1, int num2);
void	get_min_node_info (t_node *a_top, t_node *b_top, t_node *temp, int *info);

void	do_two_element(t_stack **a, t_stack **b);

void	do_partition(t_stack **a, t_stack **b, t_stat *stat);
int		select_best_idx(t_stack **a, t_stack **b, t_stat *stat);

int		find_count_rb(t_node *b_top, int idx);
int		find_count_rrb(t_node *b_top, int idx);
int		find_count_ra(t_node *a_top, int idx);
int		find_count_rra(t_node *a_top, int idx);



//마지막에 

#endif