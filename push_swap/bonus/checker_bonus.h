/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:15:13 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/22 10:45:53 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
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

void	show_error(char *message);
int		is_number(char *str);
int		check_right_cmd(char **argv);
void	init_stack(t_stack **a, t_stack **b, char **argv, t_stat *stat);
t_node	*create_node(int data);
void	push_node(t_node **head, t_node *node);
void	pop_node(t_node **head);
void	print_list(t_node **head);
void	print_list_reverse(t_node **head);
void	rotate_list(t_node **head, int count);
void	print_list_reverse_idx(t_node **head);
void	quick_sort(int *list, int first, int last);
void	sort(int **sorted_list, int count, char **argv);
void	check_same_number(int *sorted_list, int argc);
void	get_pivot(t_stat *stat, int *list, int count);
int		binary_search(int value, int start, int end, int *list);
int		get_index(int value, int *list, int count);

void	execute_s(t_stack **stack);
void	execute_p(t_stack **push_stack, t_stack **pop_stack);
void	execute_r(t_stack **stack);
void	execute_rr(t_stack **stack);
void	execute_r_both(t_stack **a, t_stack **b);
void	execute_rr_both(t_stack **a, t_stack **b);
void	execute_s_both(t_stack **a, t_stack **b);

#endif