#include "push_swap.h"

int	ft_move_to_top2(t_frame *frame )
{
	int	dec;
	int	inc;
	int	half;

	dec = ft_get_biggest((*frame));
	half = ft_get_lengt(frame->stack_b) / 2;
	if (dec < half)
	{
		while (dec-- > 0)
			ft_rb((*frame).stack_b);
		ft_pa(frame);
	}
	else
	{
		dec = ft_get_lengt(frame->stack_b) - dec ;
		while (dec-- > 0)
			ft_rrb((*frame).stack_b);
		ft_pa(frame);
	}
	return (1);
}

t_frame	*pushin_back(t_frame *frame)
{
	while (frame->stack_b)
		ft_move_to_top2(frame);
	return (frame);
}

t_frame	*ft_moving_chunk(t_frame *frame, int chunk_lenght, int	chunk_start)
{
	int	i;
	int	inc;
	int	k;

	i = 0;
	k = 0;
	chunk_lenght = ft_get_lengt(frame->stack_a) / 5;
	inc = chunk_lenght;
	while (i < 5)
	{
		while (k < chunk_lenght)
		{
			frame = pushin_chunk(frame, chunk_start, chunk_lenght);
			k++;
		}
		chunk_start += inc;
		chunk_lenght += inc;
		i++;
	}
	return (frame);
}

int	sort100element(t_frame *frame)
{
	frame = ft_moving_chunk(frame, 0, 0);
	frame->stack_lengt = ft_get_lengt(frame->stack_a);
	if (frame->stack_lengt <= 3)
	{
		if (frame->stack_lengt == 3)
			frame->stack_a = sort3element(frame->stack_a);
		else if (frame->stack_lengt == 2)
			if (frame->stack_a->value > frame->stack_a->next->value)
				frame->stack_a = ft_sa(frame->stack_a);
	}
	frame = pushin_back(frame);
	return (1);
}
