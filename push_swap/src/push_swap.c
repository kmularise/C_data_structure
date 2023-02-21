/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:49:06 by yuikim            #+#    #+#             */
/*   Updated: 2023/02/21 19:49:07 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int check_right_cmd(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if ()
			return (0);
	return (1);
}

int main(int argc, char **argv)
{
	// for (int i = 0; i < argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }
	
}