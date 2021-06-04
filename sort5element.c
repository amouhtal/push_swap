#include "push_swap.h"

void	under_mid_point(t_frame	*frame, int middle_point)
{
	int	i;

	i = 0;
	while (i++ < frame->stack_lengt)
		if(frame->stack_a->value < middle_point)
			ft_pb(frame);
		else
			frame->stack_a = ft_ra(frame->stack_a);
}

void	sorted_b_to_a(t_frame	*frame)
{
	if (frame->stack_lengt == 2)
	{
		while (frame->stack_b->prev)
			frame->stack_b = frame->stack_b->prev;
		if (frame->stack_b->value < frame->stack_b->next->value)
			frame->stack_b = ft_sb(frame->stack_b);
		ft_pa(frame);
		ft_pa(frame);
	}
	else
		ft_pa(frame);
}

t_stack *sort5element(t_frame frame)
{
	int		middle_point;
	t_stack	*tmp;

	middle_point = frame.sorted_table[frame.stack_lengt / 2];
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	tmp = frame.stack_a;
	under_mid_point(&frame, middle_point);
	frame.stack_lengt = ft_get_lengt(frame.stack_a);
	if (frame.stack_lengt == 3)
		frame.stack_a = sort3element(frame.stack_a);
	else
		if (frame.stack_a->value > frame.stack_a->next->value)
			frame.stack_a = ft_sa(frame.stack_a);
	frame.stack_lengt = ft_get_lengt(frame.stack_b);
	sorted_b_to_a(&frame);
	return (frame.stack_a);
}