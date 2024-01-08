#include "push_swap.h"

int		sorted(t_list *stack)
{
	t_list *current = stack;

	while (current)
	{
		if(current->next && current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}
int main(int argc, char **argv)
{
	t_list *stack_a = NULL;
	// t_list *stack_b = NULL;
	int i;
	i = 1;
	(void)argc;

	while (argv[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(argv[i]),&stack_a));
		i++;
	}
	if(sorted(stack_a))
	{
		printf("sorted");
	}
	swap_a(&stack_a);
	t_list *current = stack_a;
	while (current)
	{
		printf("%i ", current->number);
		current = current->next;
	}

	return 0;
}
