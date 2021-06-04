#include "push_swap.h"

t_frame	pushin_chunk(t_frame frame, int start, int fin)
{
	int		hold_first_moves;
	int		hold_second_moves;
	int		half;
	t_frame	sframe;

	hold_first_moves = ft_scan_from_top(frame, start, fin);
	hold_second_moves = ft_scan_from_bottom(frame, start, fin);
	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves-- > 0)
			frame.stack_a = ft_ra(frame.stack_a);
		ft_pb(&frame);
	}
	else
	{
		while (hold_second_moves >= 0)
		{
			frame.stack_a = ft_rra(frame.stack_a);
			hold_second_moves--;
		}
		ft_pb(&frame);
	}
	return (frame);
}

t_stack	*sort10element(t_frame frame)
{
	int		middle_point;
	int		i;
	t_stack	*tmp;

	i = 0;
	middle_point = frame.sorted_table[frame.stack_lengt / 2];
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	while (i < frame.stack_lengt)
	{
		if (frame.stack_a->value < middle_point)
			ft_pb(&frame);
		else
			frame.stack_a = ft_ra(frame.stack_a);
		i++;
	}
	while (frame.stack_b)
		ft_pb(&frame);
	return (frame.stack_a);
}

int	above_100element(t_frame *frame)
{
	int	chunk_lenght;
	int	chunk_start;
	int	i;
	int	inc;
	int	k;

	i = 0;
	k = 0;
	chunk_lenght = ft_get_lengt(frame->stack_a) / 13;
	inc = chunk_lenght;
	chunk_start = 0;
	while (i < 13)
	{
		while (k++ < chunk_lenght)
			*frame = pushin_chunk(*frame, chunk_start, chunk_lenght);
		chunk_start += inc;
		chunk_lenght += inc;
		i++;
	}
	frame->stack_lengt = ft_get_lengt(frame->stack_a);
	while (frame->stack_a)
		ft_pb(frame);
	*frame = pushin_back(*frame);
	return (1);
}

void	sort_by_lenght(t_frame *frame)
{
	if (frame->stack_lengt == 3)
		frame->stack_a = sort3element(frame->stack_a);
	else if (frame->stack_lengt > 3 && frame->stack_lengt <= 5)
		frame->stack_a = sort5element(*frame);
	else if (frame->stack_lengt > 5 && frame->stack_lengt <= 100)
		sort100element(*frame);
	else
		above_100element(frame);
}

int	main(int argc, char **argv)
{
	int		i;
	t_frame	frame;
	t_stack	*test;
	
	i = 0;
	if (argc > 1)
	{
		frame.sorted_table = sorted_table(argc, argv);
		if (!handl_error(argv))
			return (0);
		if (!deplicat_nbr(frame.sorted_table, argc - 1))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		frame.stack_a = get_stack_a(argv, frame.stack_a);
		frame.stack_lengt = ft_get_lengt(frame.stack_a);
		if (check_if_sorted(frame.stack_a))
			sort_by_lenght(&frame);
		ft_free(frame.stack_a);
		free(frame.sorted_table);
	}
	ft_print_stack(frame.stack_a);
	return (0);
}
