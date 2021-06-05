#include "push_swap.h"

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

int		ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return (1);
		++s;
	}
	return (0);
}
int		calcule_lenght(char **argv, int	lenght)
{
	int 	j = 1;
	int		j2;
	char	**tab;
	int count;

	count = 0;
	lenght = 0;
	while(argv[j])
	{
		j2 = 0;
			count = 0;
			if (ft_strchr(argv[j], ' '))
			{
				tab = ft_split(argv[j], ' ');
				while (tab[count])
				{
					lenght++;
					count++;
				}
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
	int 	j2;

	j2 = 0;
	i = 1;
	j = 0;
	new_argv = (char **)malloc(sizeof(char*) * lenght + 1);
	while (argv[i] && argv[i][0])
	{
		if (ft_strchr(argv[i], ' '))
		{
			j2 = 0;
			splited_tab = ft_split(argv[i], ' ');
			while (splited_tab[j2])
			{
				new_argv[j] = ft_strdup(splited_tab[j2]);
				j++;
				j2++;
			}
		}
		else
		{
			new_argv[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	new_argv[j] = NULL;
	return (new_argv);
}

int		*sorted_table(int lenght, char **argv, t_frame *frame)
{
	int		i;
	int		tmp;
	int		*tab;
	int 	check;
	char	**new_argv;
	int		j = 0;

	i = 0;
	check = 0;
	lenght = calcule_lenght(argv, lenght);
	new_argv = ft_new_arg(lenght, argv);
	i = 0;
	if (!handl_error(new_argv))
		return (0);
	frame->stack_a = get_stack_a(new_argv, frame->stack_a);
	tab = malloc(sizeof(int) * lenght);

	while (new_argv[i])
	{
		tab[i] = ft_atoi(new_argv[i], &check);
		if (check)
			exit(1);
		i++;
	}
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

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long long	ft_atoi(const char *str, int *check)
{
	int		i;
	long long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\v') && str[i])
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		*check = 1;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}