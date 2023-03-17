/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:41:50 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/17 23:00:54 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return 1;
	i = -1;
	while (++i < argc - 1)
	{
		if (ft_atoi(argv[i]) >= ft_atoi(argv[i + 1]))
		{
			printf("%d",ft_atoi(argv[i]));
			printf(" %d",ft_atoi(argv[i + 1]));
			return (0);
		}
	}
	return (1);
}