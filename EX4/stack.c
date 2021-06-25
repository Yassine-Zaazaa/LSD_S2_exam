#include "stack.h"

t_stack		*new_stack(char data)
{
    t_stack *node = (t_stack*)malloc(sizeof(t_stack));
    node->data = data;
    node->next = NULL;
    return node;
}

int                     is_empty(t_stack *head)
{
    return !head;
}

void		push(t_stack **head, char data)
{
    t_stack *node = new_stack(data);
    node->next = *head;
    *head = node;
    printf("%c pushed to stack\n", data);
}

int		pop(t_stack **head)
{
    if (is_empty(*head))
        return INT_MIN;
    t_stack *temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}

int		peek_stack(t_stack *head)
{
    if (is_empty(head))
        return INT_MIN;
    return head->data;
}

void		print_stack(t_stack *head)
{
	t_stack *tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}