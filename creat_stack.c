#include "push_swap.h"

t_stack	*new_stack_a(void)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	stack_a->next = NULL;
	stack_a->prev = NULL;
	return (stack_a);
}

t_stack	*add_list(t_stack *stack)
{
	t_stack	*new_stack;

	new_stack = new_stack_a();
	stack->next = new_stack;
	new_stack->prev = stack;
	return (new_stack);
}

t_stack	*get_stack_a( char **new_argv, t_stack *stack_a)
{
	int	i;

	stack_a = new_stack_a();
	i = 0;
	while (new_argv[i])
	{
		stack_a->value = ft_atoi(new_argv[i], 0);
		if (new_argv[i + 1] != NULL)
			stack_a = add_list(stack_a);
		i++;
	}
	return (stack_a);
}
