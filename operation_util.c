/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:01:01 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 13:02:52 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pa_util(t_frame *frame, t_stack *node)
{
	if (frame->stack_b)
	{
		frame->stack_b = get_head(frame->stack_b);
		node = frame->stack_b;
		frame->stack_b = frame->stack_b->next;
		frame->stack_b->prev = NULL;
		node->next = NULL;
		frame->stack_a = node;
	}
	return (node);
}

t_stack	*ft_pb_util(t_frame *frame, t_stack	*node)
{
	frame->stack_a = get_head(frame->stack_a);
	node = frame->stack_a;
	frame->stack_a = frame->stack_a->next;
	frame->stack_a->prev = NULL;
	node->next = NULL;
	frame->stack_b = node;
	return (node);
}

void	ft_pb(t_frame *frame)
{
	t_stack	*node;

	if (frame->stack_b != NULL)
	{
		frame->stack_b = get_head(frame->stack_b);
		if (frame->stack_a)
		{
			frame->stack_a = get_head(frame->stack_a);
			node = frame->stack_a;
			frame->stack_a = frame->stack_a->next;
			if (frame->stack_a)
				frame->stack_a->prev = NULL;
			frame->stack_b->prev = node;
			node->next = frame->stack_b;
		}
	}
	else
		node = ft_pb_util(frame, node);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_frame *frame)
{
	t_stack	*node;

	if (frame->stack_a != NULL)
	{
		frame->stack_a = get_head(frame->stack_a);
		if (frame->stack_b)
		{
			frame->stack_b = get_head(frame->stack_b);
			node = frame->stack_b;
			frame->stack_b = frame->stack_b->next;
			if (frame->stack_b)
				frame->stack_b->prev = NULL;
			frame->stack_a->prev = node;
			node->next = frame->stack_a;
		}
	}
	else
		node = ft_pa_util(frame, node);
	ft_putstr_fd("pa\n", 1);
}

t_stack	*ft_rrb(t_stack	*stack_b)
{
	t_stack	*tail;

	tail = NULL;
	if (ft_get_lengt(stack_b) > 1)
	{
		while (stack_b && stack_b->next)
			stack_b = stack_b->next;
		tail = stack_b;
		stack_b = stack_b->prev;
		stack_b->next = NULL;
		while (stack_b->prev)
			stack_b = stack_b->prev;
		stack_b->prev = tail;
		tail->prev = NULL;
		tail->next = stack_b;
	}
	ft_putstr_fd("rrb\n", 1);
	return (tail);
}
