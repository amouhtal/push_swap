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

int		calcule_lenght(char **argv, int	lenght)
{
	int 	j = 0;
	int		j2;
	lenght--;
	while(argv[j])
	{
		j2 = 0;
		while(argv[j][j2])
		{
			if (argv[j][j2] == ' ')
			{
				while (argv[j][j2] == ' ')
				{
					j2++;
				}
				if (argv[j][j2])
					lenght++;
			}
			j2++;
		}
		j++;
	}
	return (lenght);
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

int		*sorted_table(int lenght, char **argv)
{
	int		i;
	int		tmp;
	int		*tab;
	int 	check;
	char	**new_argv;
	char	**new_argv2;
	int		lenght2;
	int		j = 0;
	int		jj2 = 0;
	int		jjj3 = 0;
	i = 0;
	check = 0;
	lenght = calcule_lenght(argv, lenght);
	new_argv = (char **)malloc(sizeof(char*) * lenght + 1);

	while (argv[jjj3])
	{
		if (ft_strchr(argv[j], ' '))
		{
			new_argv2 = ft_split(argv[j], ' ');
			while (new_argv2[jj2])
			{
				new_argv[j] = ft_strdup(new_argv2[jj2]);
				printf("(: %s\n", new_argv2[jj2]);
				jj2++;
				j++;
			}
		}
		else
		{
			new_argv[j] = ft_strdup(argv[j + 1]);
			j++;
		}
		jjj3++;
	}
		puts("guards");
	tab = malloc(sizeof(int) * lenght);
	while (i < lenght)
	{
		tab[i] = ft_atoi(argv[i + 1], &check);
		if (check)
			exit(1);
		i++;
	}
	printf("==> %d\n", lenght);
	i = 0;
	while (i++ < lenght - 1)
		if (tab[i] > tab[i + 1])
		{ 
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
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