#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	int		i;
	int		max;
	t_stack	*tmp;

	i = 0;
	max = ft_get_lengt(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < max)
	{
		tmp = stack;
		if (stack)
			stack = stack->next;
		free(tmp);
		i++;
	}
}
