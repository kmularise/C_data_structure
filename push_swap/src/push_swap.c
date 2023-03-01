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
		if (!is_number(argv[i]))
			return (0);
	return (1);
}
void make_stack(t_stack **a, t_stack **b, char **argv)
{
	int	i;
	t_node *temp;

	i = 1;
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->head = NULL;
	(*b)->size = 0;
	(*a)->head = create_node(ft_atoi(argv[i]));
	(*a)->size = 1;
	while (argv[++i])
	{
		temp = create_node(ft_atoi(argv[i]));
		push_node(&((*a)->head), temp);
		(*a)->size += 1;
	}

}

void show_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}
int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	if (argc == 1)
		show_error("Error\n");
	if (!check_right_cmd(argv))
		show_error("Error\n");
	make_stack(&a, &b, argv);
	print_list_reverse(&(a->head));
	// printf("size :%d\n",(a.head)->data);
	// for (int i = 0; i < argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }

	
}