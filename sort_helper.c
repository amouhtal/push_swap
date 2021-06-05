#include "push_swap.h"

int		if_in_chunk(t_frame *frame,int start, int fin, int value)
{
	while (start < fin)
		if (value == frame->sorted_table[start++])
			return (1);
	return (0);
}

int		ft_scan_from_top(t_frame *frame, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (frame->stack_a->prev)
		frame->stack_a = frame->stack_a->prev;
	while (frame->stack_a->next)
	{
		if (if_in_chunk(frame, start, fin, frame->stack_a->value))
		{
			frame->hold_first = frame->stack_a->value;
				return (moves);
		}
		frame->stack_a = frame->stack_a->next;
		moves++;
	}
	return (moves);

}

int		ft_scan_from_bottom(t_frame *frame, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (frame->stack_a->next)
		frame->stack_a = frame->stack_a->next;
	while (frame->stack_a->prev)
	{
		if (if_in_chunk(frame, start, fin, frame->stack_a->value))
		{
			frame->hold_second = frame->stack_a->value;
				return (moves);
		}
		frame->stack_a = frame->stack_a->prev;
		moves++;
	}
	return (moves);
}


int	ft_get_biggest(t_frame frame)
{
	int		is_bigger;
	int		var_to_push;
	int		inc;
	int		pos;

	inc = 0;
	pos = 0;
	while (frame.stack_b->prev)
		frame.stack_b = frame.stack_b->prev;
	var_to_push = frame.stack_b->value;
	while (frame.stack_b)
	{
		if (var_to_push <= frame.stack_b->value)
		{
			var_to_push = frame.stack_b->value;
			pos = inc;
		}
		inc++;
		frame.stack_b = frame.stack_b->next;
	}
	return (pos);
}

int		check_if_sorted(t_stack *stack_a)
{
	int flag;
	int lenght;

	flag = 0;
	lenght = ft_get_lengt(stack_a);
	while (stack_a->prev)
		stack_a = stack_a->prev;
	while (lenght > 1)
	{
		if (stack_a->value > stack_a->next->value)
		{
			return (1);
		}
		stack_a = stack_a->next;
		lenght--;
	}
	return 0;
}
