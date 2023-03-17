#include "push_swap.h"

int main()
{
	t_node *head;
	t_node *temp_node;


	head = NULL;
	temp_node = create_node(0);
	push_node(&head, temp_node);
	// free(temp_node);
	// temp_node = create_node(1);
	// push_node(&head, temp_node);
	// temp_node = create_node(2);
	// push_node(&head, temp_node);
	// temp_node = create_node(3);
	// push_node(&head, temp_node);
	// temp_node = create_node(4);
	// push_node(&head, temp_node);
	pop_node(&head);
	print_list(&head);
	printf("\n");
	print_list_reverse(&head);
	rotate_list(&head, 2);
	printf("\n");
	print_list(&head);
	printf("\n");
	print_list_reverse(&head);
	// system("leaks a.out");
}