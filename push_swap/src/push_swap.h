/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:43:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/01 20:45:03 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_node {
	int				data;
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

void	execute_s(t_stack **stack);
void	execute_p(t_stack **push_stack, t_stack **pop_stack);
void	execute_r(t_stack **stack);
void	execute_rr(t_stack **stack);

void	show_error(char *message);

#endif