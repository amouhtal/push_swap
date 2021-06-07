/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:10:19 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 15:06:05 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*pushin_chunk(t_frame *frame, int start, int fin)
{
	int		hold_first_moves;
	int		hold_second_moves;

	hold_first_moves = ft_scan_from_top(frame, start, fin);
	hold_second_moves = ft_scan_from_bottom(frame, start, fin);
	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves-- > 0)
			frame->stack_a = ft_ra(frame->stack_a);
		ft_pb(frame);
	}
	else
	{
		while (hold_second_moves >= 0)
		{
			frame->stack_a = ft_rra(frame->stack_a);
			hold_second_moves--;
		}
		ft_pb(frame);
	}
	return (frame);
}

static int	above_100element(t_frame *frame)
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
			frame = pushin_chunk(frame, chunk_start, chunk_lenght);
		chunk_start += inc;
		chunk_lenght += inc;
		i++;
	}
	frame->stack_lengt = ft_get_lengt(frame->stack_a);
	while (frame->stack_a)
		ft_pb(frame);
	frame = pushin_back(frame);
	return (1);
}

static void	sort_by_lenght(t_frame *frame)
{
	if (frame->stack_lengt == 2 || frame->stack_lengt == 1)
	{
		frame->stack_a = get_head(frame->stack_a);
		if (frame->stack_a->value > frame->stack_a->next->value)
			frame->stack_a = ft_sa(frame->stack_a);
	}
	else if (frame->stack_lengt == 3)
		frame->stack_a = sort3element(frame->stack_a);
	else if (frame->stack_lengt > 3 && frame->stack_lengt <= 5)
		frame->stack_a = sort5element(frame);
	else if (frame->stack_lengt > 5 && frame->stack_lengt <= 100)
		sort100element(frame);
	else
		above_100element(frame);
}

int	main(int argc, char **argv)
{
	int		i;
	t_frame	frame;
	int		lenght;

	i = 0;
	if (argc > 1)
	{
		initilise(argc, argv, &frame);
		frame.stack_lengt = ft_get_lengt(frame.stack_a);
		lenght = ft_get_lengt(frame.stack_a);
		if (!deplicat_nbr(&frame, frame.sorted_table, lenght))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (check_if_sorted(frame.stack_a))
			sort_by_lenght(&frame);
		ft_free(frame.stack_a);
		free(frame.sorted_table);
	}
	return (0);
}
