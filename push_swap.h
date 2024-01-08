#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
	int number;
	int position;
	struct s_list *next;
} t_list;

t_list	*ft_lstnew(int content,t_list *stack_a);
void ft_lstadd_back(t_list **lst, t_list *new);
void swap_a(t_list **list);
void push_b(t_list *stack_a,t_list **stack_b);
void ft_lstadd_front(t_list **lst, t_list *new);
void rotate_a(t_list **stack);
void reverse_rotate_a(t_list **stack);
#endif
