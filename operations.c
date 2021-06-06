#include "push_swap.h"

t_stack	*ft_sa(t_stack *stack_a)
{
	int	tmp;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	tmp = stack_a->next->value;
	stack_a->next->value = stack_a->value;
	stack_a->value = tmp;
	ft_putstr_fd("sa\n", 1);
	return (stack_a);
}

t_stack	*ft_sb(t_stack *stack_b)
{
	int	tmp;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	tmp = stack_b->next->value;
	stack_b->next->value = stack_b->value;
	stack_b->value = tmp;
	ft_putstr_fd("sb\n", 1);
	return (stack_b);
}

// t_frame	*ft_ss(t_frame *frame)
// {
// 	ft_sa(frame->stack_a);
// 	ft_sb(frame->stack_b);
// 	ft_putstr_fd("ss\n", 1);
// 	return (frame);
// }

t_stack	*ft_ra(t_stack	*stack_a)
{
	t_stack	*head;
	t_stack	*ret;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	head = stack_a;
	stack_a = stack_a->next;
	ret = stack_a;
	stack_a->prev = NULL;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = head;
	head->prev = stack_a;
	head->next = NULL;
	ft_putstr_fd("ra\n", 1);
	return (ret);
}

t_stack	*ft_rb(t_stack *stack_b)
{
	t_stack	*head;
	t_stack	*ret;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	head = stack_b;
	stack_b = stack_b->next;
	ret = stack_b;
	stack_b->prev = NULL;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = head;
	head->prev = stack_b;
	head->next = NULL;
	ft_putstr_fd("rb\n", 1);
	return (ret);
}

t_stack	*ft_rra(t_stack *stack_a)
{
	t_stack	*tail;

	while (stack_a->next)
		stack_a = stack_a->next;
	tail = stack_a;
	stack_a = stack_a->prev;
	stack_a->next = NULL;
	while (stack_a->prev)
		stack_a = stack_a->prev;
	stack_a->prev = tail;
	tail->prev = NULL;
	tail->next = stack_a;
	ft_putstr_fd("rra\n", 1);
	return (tail);
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
