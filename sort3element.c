#include "push_swap.h"

int		cases(int f_value, int	s_value, int l_value)
{

	if (f_value > s_value && s_value < l_value && l_value > f_value)
		return (1);
	else if (f_value > s_value && s_value > l_value && l_value < f_value)
		return (2);
	else if (f_value > s_value && s_value < l_value && l_value < f_value)
		return (3);
	else if (f_value < s_value && s_value > l_value && l_value > f_value)
		return (4);
	else if (f_value < s_value && s_value > l_value && l_value < f_value)
		return (5);
	return (0);
}

t_stack *sort3element(t_stack *stack)
{
	int f_value;
	int s_value;
	int l_value;

	while (stack->prev)
		stack = stack->prev;
	f_value =  stack->value;
	s_value =  stack->next->value;
	l_value =  stack->next->next->value;
	if (cases(f_value, s_value, l_value) == 1)
		stack = ft_sa(stack);
	else if (cases(f_value, s_value, l_value) == 2)
	{
		stack = ft_sa(stack);
		stack = ft_rra(stack);
	}
	else if (cases(f_value, s_value, l_value) == 3)
		stack = ft_ra(stack);
	else if (cases(f_value, s_value, l_value) == 4)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
	}
	else if (cases(f_value, s_value, l_value) == 5)
		stack = ft_rra(stack);
	return (stack);
}