#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
typedef	struct s_node {
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int size;
	struct s_node *head;
} t_stack;

t_node	*create_node(int data);
void	push_node(t_node **head, t_node *node);
void	print_list(t_node **head);
void	print_list_reverse(t_node **head);
void	pop_node(t_node **head);
void	rotate_list(t_node **head, int count);
#endif