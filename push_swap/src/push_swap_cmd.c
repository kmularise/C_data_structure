/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:25:40 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/07 17:04:28 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_s(t_stack **stack)
{
	t_node	*top_node;
	int		temp;
	int		temp_idx;

	if ((*stack)->size < 2)
		return;
	top_node = (*stack)->top;
	temp = top_node->data;
	temp_idx = top_node->idx;
	top_node->data = top_node->next->data;
	top_node->idx = top_node->next->idx;
	top_node->next->data = temp;
	top_node->next->idx = temp_idx;
}

void	execute_p(t_stack **push_stack, t_stack **pop_stack)
{
	t_node	*temp_node;
	int		temp;
	int		temp_idx;

	if ((*pop_stack)->size == 0)
		return ;
	temp = (*pop_stack)->top->data;
	temp_idx = (*pop_stack)->top->idx;
	(*pop_stack)->size-=1;
	pop_node(&(*pop_stack)->top);
	temp_node = create_node(temp);
	temp_node->idx = temp_idx;
	push_node(&((*push_stack)->top), temp_node);
	(*push_stack)->size+=1;
}

void	execute_r(t_stack **stack)
{
	rotate_list(&((*stack)->top), 1);
}

void	execute_rr(t_stack **stack)
{
	rotate_list(&((*stack)->top), -1);
}
