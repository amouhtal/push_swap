#include "push_swap.h"

int	ft_get_lengt(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	calcule_lenght(char **argv, int	lenght)
{
	int		j;
	int		j2;
	char	**tab;
	int		count;

	count = 0;
	lenght = 0;
	j = 1;
	while (argv[j])
	{
		j2 = 0;
		count = 0;
		if (ft_strchr(argv[j], ' '))
		{
			tab = ft_split(argv[j], ' ');
			while (tab[count++])
				lenght++;
		}
		else
			lenght++;
		j++;
	}
	return (lenght);
}

char	**ft_new_arg(int	lenght, char **argv)
{
	char	**new_argv;
	char	**splited_tab;
	int		i;
	int		j;
	int		j2;

	j2 = 0;
	i = 1;
	j = 0;
	new_argv = (char **)malloc(sizeof(char *) * lenght + 1);
	while (argv[i] && argv[i][0])
	{
		if (ft_strchr(argv[i], ' '))
		{
			j2 = 0;
			splited_tab = ft_split(argv[i], ' ');
			while (splited_tab[j2])
				new_argv[j++] = ft_strdup(splited_tab[j2++]);
		}
		else
			new_argv[j++] = ft_strdup(argv[i]);
		i++;
	}
	new_argv[j] = NULL;
	return (new_argv);
}

int	*sort_table(int	*tab, int lenght)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < lenght - 1)
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

void	initilise(int lenght, char **argv, t_frame *frame)
{
	int		i;
	int		check;
	char	**new_argv;
	int		j;

	i = 0;
	j = 0;
	check = 0;
	lenght = calcule_lenght(argv, lenght);
	new_argv = ft_new_arg(lenght, argv);
	i = 0;
	if (!handl_error(new_argv))
		exit(1);
	frame->stack_a = get_stack_a(new_argv, frame->stack_a);
	frame->sorted_table = malloc(sizeof(int) * lenght);
	while (new_argv[i])
	{
		frame->sorted_table[i] = ft_atoi(new_argv[i], &check);
		if (check)
			exit(1);
		i++;
	}
	frame->sorted_table = sort_table(frame->sorted_table, lenght);
}
