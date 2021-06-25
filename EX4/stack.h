#ifndef STACK_H
# define STACK_H

// Include the necessary libraries
# include <stdlib.h>
# include <stdio.h>
# include <limits.h> // Contains INT_MIN definition
# include <string.h>
// The stack struct
typedef struct			s_stack
{
	char			data;
	struct s_stack		*next;
}				t_stack;

/* ************************************************************************** */
/*                        STACK FUNCTIONS                                     */
/* ************************************************************************** */
t_stack                	*new_stack(char data);
int			is_empty(t_stack *head);
void                 	push(t_stack **head, char data);
int			pop(t_stack **head);
int              	stack_len(t_stack *head);
int			peek_stack(t_stack *head);
void			print_stack(t_stack *head);
#endif