#include "push_swap.h"

int		*sorted_table(int lenght, char **argv)
{
	int		i;
	int		tmp;
	int		*tab;
	int 	check;

	i = 0;
	check = 0;
	tab = malloc(sizeof(int) * lenght - 1);
	while (i < lenght - 1)
	{
		tab[i] = ft_atoi(argv[i + 1], &check);
		if (check)
			exit(1);
		i++;
	}
	i = 0;
	while (i < lenght - 2)
	{
		if (tab[i] > tab[i + 1])
		{ 
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab);
}

int ft_get_lengt(t_stack *stack)
{
	int i;

	i = 0;
	while (stack && stack->prev)
		stack =  stack->prev;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return(i);
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
	if (f_value > s_value && s_value < l_value && l_value > f_value)
		stack = ft_sa(stack);
	else if (f_value > s_value && s_value > l_value && l_value < f_value)
	{
		stack = ft_sa(stack);
		stack = ft_rra(stack);
	}
	else if (f_value > s_value && s_value < l_value && l_value < f_value)
		stack = ft_ra(stack);
	else if (f_value < s_value && s_value > l_value && l_value > f_value)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
	}
	else if (f_value < s_value && s_value > l_value && l_value < f_value)
		stack = ft_rra(stack);
	
	return (stack);
}

t_stack *sort5element(t_frame frame)
{
	int middle_point;
	int i;

	t_stack *tmp;
	i = 0;
	middle_point = frame.sorted_table[frame.stack_lengt / 2];
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	tmp = frame.stack_a;
	while (i < frame.stack_lengt)
	{
		if(frame.stack_a->value < middle_point)
			ft_pb(&frame);
		else
			frame.stack_a = ft_ra(frame.stack_a);
		i++;
	}
	frame.stack_lengt = ft_get_lengt(frame.stack_a);
	if (frame.stack_lengt == 3)
		frame.stack_a = sort3element(frame.stack_a);
	else
	{
		if (frame.stack_a->value > frame.stack_a->next->value)
			frame.stack_a = ft_sa(frame.stack_a);
	}
	frame.stack_lengt = ft_get_lengt(frame.stack_b);
	if(frame.stack_lengt == 2)
	{
		while (frame.stack_b->prev)
			frame.stack_b = frame.stack_b->prev;
		if(frame.stack_b->value < frame.stack_b->next->value)
			frame.stack_b = ft_sb(frame.stack_b);
		ft_pa(&frame);
		ft_pa(&frame);
	}
	else
		ft_pa(&frame);
	return(frame.stack_a);
}


int	ft_is_smaller(t_frame frame)
{
	int		is_smaller;
	int		var_to_push;

	is_smaller = 1;
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	var_to_push = frame.stack_a->value;
	if (frame.stack_b)
	{
		while (frame.stack_b->prev)
			frame.stack_b = frame.stack_b->prev;
		while (frame.stack_b->next)
		{
			if (frame.stack_b->value < var_to_push)
				is_smaller = 0;
			frame.stack_b = frame.stack_b->next;
		}
	}
	return (is_smaller);
}

int	ft_is_bigger(t_frame frame)
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
	while (frame.stack_b->next)
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

int		if_in_chunk(t_frame frame,int start, int fin, int value)
{
	while (start <fin)
		if (value == frame.sorted_table[start++])
			return (1);
	return (0);
}

int		chunk1_not_in_stack_a(t_frame frame,int start, int fin)
{
	int value;
	t_stack *tmp;
	int i;

	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	while (ft_get_lengt(frame.stack_a))
	{
		i = start;
		value = frame.stack_a->value;
		while (i < fin)
		{
			if (value == frame.sorted_table[i])
				return (1);
			i++;
		}
		frame.stack_a = frame.stack_a->next;
	}
	return (0);
}

int		ft_scan_from_top(t_frame frame, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	while (frame.stack_a->next)
	{
		if (if_in_chunk(frame, start, fin, frame.stack_a->value))
		{
			frame.hold_first = frame.stack_a->value;
				return (moves);
		}
		frame.stack_a = frame.stack_a->next;
		moves++;
	}
	return (moves);

}

int		ft_scan_from_bottom(t_frame frame, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (frame.stack_a->next)
		frame.stack_a = frame.stack_a->next;
	while (frame.stack_a->prev)
	{
		if (if_in_chunk(frame, start, fin, frame.stack_a->value))
		{
			frame.hold_second = frame.stack_a->value;
				return (moves);
		}
		frame.stack_a = frame.stack_a->prev;
		moves++;
	}
	return (moves);
}


t_frame pushin_chunk(t_frame frame, int start, int fin)
{
	int hold_first_moves;
	int	hold_second_moves;
	int is_smaller;
	int	is_bigger;
	int	half;

	t_frame sframe;

	is_smaller = 0;
	is_bigger = 1;
	hold_first_moves = ft_scan_from_top(frame, start, fin);
	hold_second_moves = ft_scan_from_bottom(frame, start, fin);

	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves > 0)
		{
			frame.stack_a = ft_ra(frame.stack_a);
			hold_first_moves--;
		}
		ft_pb(&frame);
	}
	else
	{
		while(hold_second_moves >= 0)
		{
			frame.stack_a = ft_rra(frame.stack_a );
			hold_second_moves--;
		}
		ft_pb(&frame);
	}
	return (frame);
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

int	ft_move_to_top(t_frame *frame)
{
	int dec;
	int inc;

	dec = ft_get_biggest((*frame));
	inc = dec;
	while (dec > 0)
	{
		ft_rb((*frame).stack_b);
		dec--;
	}
	ft_pa(frame);
	while (inc > 0)
	{
		ft_rrb(frame->stack_b);
		inc--;
	}
	return 1;
}


t_stack *sort10element(t_frame frame)
{
	int middle_point;
	int i;
	t_stack *tmp;

	i = 0;
	middle_point = frame.sorted_table[frame.stack_lengt / 2];
	while (frame.stack_a->prev)
		frame.stack_a = frame.stack_a->prev;
	while (i < frame.stack_lengt)
	{
		if(frame.stack_a->value < middle_point)
			ft_pb(&frame);
		else
			frame.stack_a = ft_ra(frame.stack_a);
		i++;
	}
	while (frame.stack_b)
		ft_pb(&frame);
	return(frame.stack_a);
}

int		above_100element(t_frame *frame)
{
	int chunk_lenght;
	int	chunk_start;
	int	i;
	int	inc;
	int ret;
	int	k = 0;

	i = 0;
	chunk_lenght = ft_get_lengt(frame->stack_a) / 13;
	inc = chunk_lenght;
	chunk_start = 0;

	while (i < 13)
	{
		while (k < chunk_lenght)
		{
			*frame = pushin_chunk(*frame, chunk_start, chunk_lenght);
			k++;
		}
		chunk_start  += inc;
		chunk_lenght += inc;
		i++;
	}
	frame->stack_lengt = ft_get_lengt(frame->stack_a);
	while (frame->stack_a)
	{
		ft_pb(frame);
	}
	*frame = pushin_back(*frame);
	return (1);
}

int deplicat_nbr(int	*table, int lenght)
{
	int i;
	int	j;

	j = 1;
	i = 0;
	while (i < lenght)
	{
		if (i + 1 < lenght)
		{
			if (table[i] == table[i + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

void ft_free(t_stack *stack)
{
	int i;
	int max;
	i = 0;

	t_stack *tmp;
	max = ft_get_lengt(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < max)
	{
		tmp = stack;
		if (stack)
			stack = stack->next;
		free(tmp);
		i++;
	}
}

int main(int argc , char **argv)
{
	int i;
	int j;
	int ii;

	t_frame frame;
	t_stack *test;
	j = 1;
	i = 0;
	if (argc > 2)
	{
		frame.sorted_table = sorted_table(argc, argv);
		while (argv[j])
		{
			i = 0;
			while (i < argv[j][i])
			{
				if (ft_isdigit(argv[j][i]) == 0)
				{
					if(!(i == 0 && (argv[j][i] == '-' || argv[j][i] == '+')))
					{
						ft_putstr_fd("Error\n", 2);
						return (0);
					}
				}
				i++;
			}
			j++;
		}
		if (!deplicat_nbr(frame.sorted_table, argc - 1))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		frame.stack_a = get_stack_a(argv,frame.stack_a);
		frame.stack_lengt = ft_get_lengt(frame.stack_a);
		if (check_if_sorted(frame.stack_a))
		{
			if(frame.stack_lengt == 3)
				frame.stack_a = sort3element(frame.stack_a);
			else if (frame.stack_lengt > 3 && frame.stack_lengt <= 5)
				frame.stack_a = sort5element(frame);
			else if (frame.stack_lengt > 5 && frame.stack_lengt <= 100)
				sort100element(frame);
			else
				above_100element(&frame);
			ft_print_stack(frame.stack_a);
		}
		ft_free(frame.stack_a);
		free(frame.sorted_table);
	}
	return(0);
}
