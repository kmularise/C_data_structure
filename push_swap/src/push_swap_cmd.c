/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:25:40 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/01 19:57:11 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_s(t_stack **stack)
{
	t_node	*top_node;
	int		temp;

	if ((*stack)->size < 2)
		return;
	top_node = (*stack)->top;
	temp = top_node->data;
	top_node->data = top_node->next->data;
	top_node->next->data = temp;
}

void	execute_p(t_stack **push_stack, t_stack **pop_stack)
{
	t_node	*temp_node;
	int		temp;

	if ((*pop_stack)->size == 0)
		return ;
	temp = (*pop_stack)->top->data;
	(*pop_stack)->size-=1;
	pop_node(&(*pop_stack)->top);
	temp_node = create_node(temp);
	push_node(&((*push_stack)->top), temp_node);
	(*pop_stack)->size+=1;
}

void	execute_r(t_stack **stack)
{
	rotate_list(&((*stack)->top), -1);
}

void	execute_rr(t_stack **stack)
{
	rotate_list(&((*stack)->top), 1);
}
