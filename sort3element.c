/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:46:02 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 14:46:04 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cases(int f_value, int	s_value, int l_value)
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

t_stack	*sort3element(t_stack *stack)
{
	int	f_value;
	int	s_value;
	int	l_value;

	stack = get_head(stack);
	f_value = stack->value;
	s_value = stack->next->value;
	l_value = stack->next->next->value;
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
