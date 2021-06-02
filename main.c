#include "push_swap.h"

void ft_print_stack(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
		{
			printf("%u\n",stack->value);
			stack = stack->next;
		}
}

t_stack *new_stack_a()
{
	t_stack *stack_a;

	stack_a = malloc(sizeof(t_stack));
	stack_a->next = NULL;
	stack_a->prev = NULL;
	return (stack_a);
}

t_stack *add_list(t_stack *stack)
{
	t_stack *new_stack;

	new_stack = new_stack_a();
	stack->next = new_stack;
	new_stack->prev = stack;
	return (new_stack);
}

t_stack    *get_stack_a( char **argv,t_stack *stack_a)
{
	int	i;

	stack_a = new_stack_a();
	i = 1;
	while (argv[i])
	{
		stack_a->value = ft_atoi(argv[i]);
		if(argv[i + 1] != NULL)
			stack_a = add_list(stack_a);
		i++;
	}
	return (stack_a);
}

int		*sorted_table(int lenght, char **argv)
{
	int		i;
	int		tmp;
	int		*tab;
	
	i = 0;
	tab = malloc(sizeof(int) * lenght - 1);
	while (i < lenght - 1)
	{
		tab[i] = atoi(argv[i + 1]);
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

t_stack *sort5element(t_vars vars)
{
	int middle_point;
	int i;
	
	t_stack *tmp;
	i = 0;
	middle_point = vars.sorted_table[vars.stack_lengt / 2];
	while (vars.stack_a->prev)
		vars.stack_a = vars.stack_a->prev;
	tmp = vars.stack_a;
	while (i < vars.stack_lengt)
	{
		if(vars.stack_a->value < middle_point)
			ft_pb(&vars);
		else
			vars.stack_a = ft_ra(vars.stack_a);
		i++;
	}
	vars.stack_lengt = ft_get_lengt(vars.stack_a);
	if (vars.stack_lengt == 3)
		vars.stack_a = sort3element(vars.stack_a);
	else
	{
		if (vars.stack_a->value > vars.stack_a->next->value)
			vars.stack_a = ft_sa(vars.stack_a);
	}
	vars.stack_lengt = ft_get_lengt(vars.stack_b);
	if(vars.stack_lengt == 2)
	{
		while (vars.stack_b->prev)
			vars.stack_b = vars.stack_b->prev;
		if(vars.stack_b->value < vars.stack_b->next->value)
			vars.stack_b = ft_sb(vars.stack_b);
		ft_pa(&vars);
		ft_pa(&vars);
	}
	else
		ft_pa(&vars);
	return(vars.stack_a);
}


int	ft_is_smaller(t_vars vars)
{
	int		is_smaller;
	int		var_to_push;

	is_smaller = 1;
	while (vars.stack_a->prev)
		vars.stack_a = vars.stack_a->prev;
	var_to_push = vars.stack_a->value;
	if (vars.stack_b)
	{
		while (vars.stack_b->prev)
			vars.stack_b = vars.stack_b->prev;
		while (vars.stack_b->next)
		{
			if (vars.stack_b->value < var_to_push)
				is_smaller = 0;
			vars.stack_b = vars.stack_b->next;
		}
	}
	return (is_smaller);
}

int	ft_is_bigger(t_vars vars)
{
	int		is_bigger;
	int		var_to_push;
	int		inc;
	int		pos;

	inc = 0;
	pos = 0;
	while (vars.stack_b->prev)
		vars.stack_b = vars.stack_b->prev;
	var_to_push = vars.stack_b->value;
	while (vars.stack_b->next)
	{
		if (var_to_push <= vars.stack_b->value)
		{
			
			var_to_push = vars.stack_b->value;
			pos = inc;
		}
		inc++;
		vars.stack_b = vars.stack_b->next;
	}
	return (pos);
}

int		if_in_chunk(t_vars vars,int start, int fin, int value)
{
	while (start <fin)
		if (value == vars.sorted_table[start++])
			return (1);
	return (0);
}

int		chunk1_not_in_stack_a(t_vars vars,int start, int fin)
{
	int value;
	t_stack *tmp;
	int i;

	while (vars.stack_a->prev)
		vars.stack_a = vars.stack_a->prev;
	while (ft_get_lengt(vars.stack_a))
	{
		i = start;
		value = vars.stack_a->value;
		while (i < fin)
		{
			if (value == vars.sorted_table[i])
				return (1);
			i++;
		}
		vars.stack_a = vars.stack_a->next;
	}
	return (0);
}

int		ft_scan_from_top(t_vars vars, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (vars.stack_a->prev)
		vars.stack_a = vars.stack_a->prev;
	while (vars.stack_a->next)
	{
		if (if_in_chunk(vars, start, fin, vars.stack_a->value))
		{
			vars.hold_first = vars.stack_a->value;
				return (moves);
		}
		vars.stack_a = vars.stack_a->next;
		moves++;
	}
	return (moves);

}

int		ft_scan_from_bottom(t_vars vars, int start, int fin)
{
	int		lenght;
	int		moves;

	moves = 0;
	while (vars.stack_a->next)
		vars.stack_a = vars.stack_a->next;
	while (vars.stack_a->prev)
	{
		if (if_in_chunk(vars, start, fin, vars.stack_a->value))
		{
			vars.hold_second = vars.stack_a->value;
				return (moves);
		}
		vars.stack_a = vars.stack_a->prev;
		moves++;
	}
	return (moves);
}


t_vars pushin_chunk(t_vars vars, int start, int fin)
{
	int hold_first_moves;
	int	hold_second_moves;
	int is_smaller;
	int	is_bigger;
	int	half;

	t_vars svars;

	is_smaller = 0;
	is_bigger = 1;
	hold_first_moves = ft_scan_from_top(vars, start, fin);
	hold_second_moves = ft_scan_from_bottom(vars, start, fin);

	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves > 0)
		{
			vars.stack_a = ft_ra(vars.stack_a);
			hold_first_moves--;
		}
		ft_pb(&vars);
	}
	else
	{
		while(hold_second_moves >= 0)
		{
			vars.stack_a = ft_rra(vars.stack_a );
			hold_second_moves--;
		}
		ft_pb(&vars);
	}
	return (vars);
}

int	ft_get_biggest(t_vars vars)
{
	int		is_bigger;
	int		var_to_push;
	int		inc;
	int		pos;

	inc = 0;
	pos = 0;
	while (vars.stack_b->prev)
		vars.stack_b = vars.stack_b->prev;
	var_to_push = vars.stack_b->value;
	while (vars.stack_b)
	{
		if (var_to_push <= vars.stack_b->value)
		{
			var_to_push = vars.stack_b->value;
			pos = inc;
		}
		inc++;
		vars.stack_b = vars.stack_b->next;
	}
	return (pos);
}

int	ft_move_to_top(t_vars *vars)
{
	int dec;
	int inc;
	dec = ft_get_biggest((*vars));

	inc = dec;
	while (dec > 0)
	{
		ft_rb((*vars).stack_b);
		dec--;
	}
	ft_pa(vars);
	while (inc > 0)
	{
		ft_rrb(vars->stack_b);
		inc--;
	}
	return 1;
}

int	ft_move_to_top2(t_vars *vars )
{
	int dec;
	int inc;
	int half;

	dec = ft_get_biggest((*vars));
	half = ft_get_lengt(vars->stack_b) / 2;

	if (dec < half)
	{
		while (dec > 0)
		{
			ft_rb((*vars).stack_b);
			dec--;
		}
		ft_pa(vars);
	}
	else
	{
		dec = ft_get_lengt(vars->stack_b) - dec ;
		while (dec > 0)
		{
			ft_rrb((*vars).stack_b);
			dec--;
		}
		ft_pa(vars);
	}
	return (1);
}

t_vars	pushin_back(t_vars vars)
{
	while (vars.stack_b)
	{
		ft_move_to_top2(&vars);
	}
	return vars;
}
t_stack *sort10element(t_vars vars)
{
	int middle_point;
	int i;
	t_stack *tmp;

	i = 0;
	middle_point = vars.sorted_table[vars.stack_lengt / 2];
	while (vars.stack_a->prev)
		vars.stack_a = vars.stack_a->prev;
	while (i < vars.stack_lengt)
	{
		if(vars.stack_a->value < middle_point)
			ft_pb(&vars);
		else
			vars.stack_a = ft_ra(vars.stack_a);
		i++;
	}
	// vars.stack_lengt = ft_get_lengt(vars.stack_a);
	// if (vars.stack_lengt > 3 && vars.stack_lengt <= 5)
	// 	vars.stack_a  = sort5element(vars);
	// if (vars.stack_lengt == 3)
	// 	vars.stack_a = sort3element(vars.stack_a);
	// else
	// 	if (vars.stack_a->value > vars.stack_a->next->value)
	// 		vars.stack_a = ft_sa(vars.stack_a);
	// vars.stack_lengt = ft_get_lengt(vars.stack_b);

	while (vars.stack_b)
	{
		ft_pb(&vars);
	}
	return(vars.stack_a);
}


int		sort100element(t_vars vars)
{
	int chunk_lenght;
	int	chunk_start;
	int	i;
	int	inc;
	int ret;
	int	k = 0;

	i = 0;
	chunk_lenght = ft_get_lengt(vars.stack_a) / 5;
	inc = chunk_lenght;
	chunk_start = 0;

	while (i < 5)
	{
		while (k < chunk_lenght)
		{
			vars = pushin_chunk(vars, chunk_start, chunk_lenght);
			k++;
		}
		chunk_start  += inc;
		chunk_lenght += inc;
		i++;
	}
	vars.stack_lengt = ft_get_lengt(vars.stack_a);
	if (vars.stack_lengt <= 3)
	{
		if (vars.stack_lengt == 3)
			vars.stack_a = sort3element(vars.stack_a);
		else if (vars.stack_lengt == 2)
			if (vars.stack_a->value > vars.stack_a->next->value)
				vars.stack_a = ft_sa(vars.stack_a);
	}
	vars = pushin_back(vars);
	return (1);

}

int		above_100element(t_vars *vars)
{
	int chunk_lenght;
	int	chunk_start;
	int	i;
	int	inc;
	int ret;
	int	k = 0;

	i = 0;
	chunk_lenght = ft_get_lengt(vars->stack_a) / 13;
	inc = chunk_lenght;
	chunk_start = 0;

	while (i < 13)
	{
		while (k < chunk_lenght)
		{
			*vars = pushin_chunk(*vars, chunk_start, chunk_lenght);
			k++;
		}
		chunk_start  += inc;
		chunk_lenght += inc;
		i++;
	}
	vars->stack_lengt = ft_get_lengt(vars->stack_a);
	while (vars->stack_a)
	{
		ft_pb(vars);
	}
	*vars = pushin_back(*vars);
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
			if (table[i] == table[i + 1] || (unsigned long long)table[i] > 2147483647)
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
	t_stack *tmp;
	i = 0;
	max =ft_get_lengt(stack);
	while (stack->prev)
	{
		stack = stack->prev;
	}
	
	while (i < max)
	{
	printf("==> %d\n",ft_get_lengt(stack) );
		tmp = stack;
		if(stack)
		stack = stack->next;
		puts("here");
		free(tmp);
		i++;
	}
}
int main(int argc , char **argv)
{
	int i;
	int j;
	int ii;

	t_vars vars;
	t_stack *test;
	j = 1;
	i = 0;
	if (argc > 2)
	{
		vars.sorted_table = sorted_table(argc, argv);
		while (argv[j])
		{
			i = 0;
			while (i < argv[j][i])
			{
				if (ft_isdigit(argv[j][i]) == 0)
				{
					ft_putstr_fd("Error\n", 2);
					return (0);
				}
					i++;
			}
			j++;
		}
		if (!deplicat_nbr(vars.sorted_table, argc - 1))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		vars.stack_a = get_stack_a(argv,vars.stack_a);
		vars.stack_lengt = ft_get_lengt(vars.stack_a);
		if (check_if_sorted(vars.stack_a))
		{
			if(vars.stack_lengt == 3)
				vars.stack_a = sort3element(vars.stack_a);
			else if (vars.stack_lengt > 3 && vars.stack_lengt <= 5)
				vars.stack_a = sort5element(vars);
			else if (vars.stack_lengt > 5 && vars.stack_lengt <= 100)
				sort100element(vars);
			else
				above_100element(&vars);
		ft_print_stack(vars.stack_a);
		}
		ft_free(vars.stack_a);
		free(vars.sorted_table);
	}
	return(0);
}
