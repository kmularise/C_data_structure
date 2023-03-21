/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:08:35 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 22:27:03 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	*line;
	char	**cmd_set;
	int		idx;

	if (argc == 1)
		return (0);
	idx = 0;
	cmd_set = malloc(sizeof(char *) * (argc - 1)); // 개수가 정해지지 않아서 연결리스트로 해야함.
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cmd_set[idx] = line;
		free(line);
	}
	ft_printf("check last %s",line);
}
