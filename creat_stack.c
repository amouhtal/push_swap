#include "push_swap.h"

void ft_print_stack(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
	{
		printf("%d\n",stack->value);
		stack = stack->next;
	}
}

t_stack *new_stack_a()
{
	t_stack *stack_a;

	stack_a = malloc(sizeof(t_stack));
	stack_a->next = NULL;
	stack_a->prev = NULL;
	return (stack_a);
}

t_stack *add_list(t_stack *stack)
{
	t_stack *new_stack;

	new_stack = new_stack_a();
	stack->next = new_stack;
	new_stack->prev = stack;
	return (new_stack);
}

t_stack    *get_stack_a( char **argv, t_stack *stack_a)
{
	int	i;

	stack_a = new_stack_a();
	i = 1;
	while (argv[i])
	{
		stack_a->value = ft_atoi(argv[i], 0);
		if(argv[i + 1] != NULL)
			stack_a = add_list(stack_a);
		i++;
	}
	return (stack_a);
}