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
		if (is_number(argv[i]))
			return (0);
	return (1);
}
void make_stack(t_stack *a, t_stack *b, char **argv)
{
	int	i;
	t_node *temp;

	i = 0;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->size = 0;
	a->head = create_node(argv[0]);
	a->size = 0;
	while (argv[i])
	{
		temp = create_node(argv[i]);
		push_node(&(a->head), temp);
		(a->size)++;
		i++;
	}

}
int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (check_right_cmd(argv))
		make_stack(&a, &b, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	
}