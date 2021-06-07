/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:46:50 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 14:46:51 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	check;

	stack_a = new_stack_a();
	i = 0;
	check = 0;
	while (new_argv[i])
	{
		stack_a->value = ft_atoi(new_argv[i], &check);
		if (check)
			exit(1);
		if (new_argv[i + 1] != NULL)
			stack_a = add_list(stack_a);
		i++;
	}
	return (stack_a);
}
