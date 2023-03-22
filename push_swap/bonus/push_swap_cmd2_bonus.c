/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:41:07 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/22 11:59:21 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_rr_both(t_stack **a, t_stack **b)
{
	execute_rr(a);
	execute_rr(b);
}

void	execute_s_both(t_stack **a, t_stack **b)
{
	execute_s(a);
	execute_s(b);
}
